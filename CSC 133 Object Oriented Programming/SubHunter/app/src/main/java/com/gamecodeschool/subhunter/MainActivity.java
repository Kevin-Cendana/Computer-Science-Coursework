/* A2 Summary
* - The old code had functions for: starting a new game, drawing, taking a shot, hit detection, & debugging.
* - Steps taken to create new, refactored code:
*   - Create classes for Submarine, Player.
*   - Create interface /  abstract class for Drawable entities (Player, Submarine, Grid)
*   - Apply encapsulation (private classes, getters/setters)
*  todo:
*   - Consolidate code into GameLogic / GameView based on if it's for drawing or logc
*   - Apply polymorphism: simplify conditional logic based on data types
*   - Break down long functions (ex. Draw everything in a loop)
*   - Fix the draw for loop around line 110
* */

package com.gamecodeschool.subhunter;
import android.app.Activity;
import android.os.Build;
import android.os.Bundle;
import android.view.MotionEvent;
import android.util.Log;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Point;
import android.view.Display;
import android.widget.ImageView;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class MainActivity extends Activity {
    int numberHorizontalPixels;
    int numberVerticalPixels;
    int blockSize;
    int gridWidth = 40;
    int gridHeight;
    float horizontalTouched = -100;
    float verticalTouched = -100;
    boolean hit = false;
    int distanceFromSub;
    boolean debugging = false;

    // Entities
    private Submarine submarine;
    private Player player;
    private Shot shot;
    private Grid grid;
    private List<Drawable> drawables = new ArrayList<>(); // List of entities to be drawn

    // Here are all the objects(instances) of classes that we need to do some drawing
    ImageView gameView;
    Bitmap blankBitmap;
    Canvas canvas;
    Paint paint;


    /* Android runs this code just before the app is seen by the player. This makes it a good place to add
        the code that is needed for the one-time setup. */
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        // Get the current device's screen resolution
        Display display = getWindowManager().getDefaultDisplay();
        Point size = new Point();
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB_MR2) {
            display.getSize(size);
        }

        // Initialize our size based variables based on the screen resolution
        numberHorizontalPixels = size.x;
        numberVerticalPixels = size.y;
        blockSize = numberHorizontalPixels / gridWidth;
        gridHeight = numberVerticalPixels / blockSize;

        // Initialize all the objects ready for drawing
        blankBitmap = Bitmap.createBitmap(numberHorizontalPixels,
                numberVerticalPixels,
                Bitmap.Config.ARGB_8888);

        canvas = new Canvas(blankBitmap);
        gameView = new ImageView(this);
        paint = new Paint();

        // Tell Android to set our drawing as the view for this app
        setContentView(gameView);

        // Create all entities
        super.onCreate(savedInstanceState);
        submarine = new Submarine();
        player = new Player();
        grid = new Grid(gridWidth, gridHeight, blockSize);

        Log.d("Debugging", "In onCreate");
        newGame();
        draw();
    }

    /* This code will execute when a new game needs to be started.
    It will happen when the app is first started and after the player wins a game. */
    void newGame(){
        // Place sub in random spot
        Random random = new Random();
        submarine.placeSubmarine(random.nextInt(gridWidth), random.nextInt(gridHeight));
        Log.d("Debugging", "In newGame");
    }

    /* Here we will do all the drawing. The grid lines, the HUD and the touch indicator*/
    void draw() {
        gameView.setImageBitmap(blankBitmap);

        // Draw all entities in a loop
        for (Drawable drawable : drawables) {
            drawable.draw(canvas, paint, blockSize);
        }

        // Wipe the screen with a white color
        canvas.drawColor(Color.argb(255, 255, 255, 255));

        // Change the paint color to black
        paint.setColor(Color.argb(255, 0, 0, 0));

        // Re-size the text appropriate for the score and distance text
        paint.setTextSize(blockSize * 2);
        paint.setColor(Color.argb(255, 0, 0, 255));
        canvas.drawText(
                "Shots Taken: " + player.getShotsTaken() +
                        "  Distance: " + distanceFromSub,
                blockSize, blockSize * 1.75f,
                paint);


        Log.d("Debugging", "In draw");
        if (debugging) {
            printDebuggingText();
        }
    }

    /* This part of the code will handle detecting that the player has tapped the screen */
    @Override
    public boolean onTouchEvent(MotionEvent motionEvent) {
        Log.d("Debugging", "In onTouchEvent");
        // Has the player removed their finger from the screen?
        if((motionEvent.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_UP) {

            // Process the player's shot by passing the
            // coordinates of the player's finger to takeShot
            takeShot(motionEvent.getX(), motionEvent.getY());
        }

        return true;
    }


    /* The code here will execute when the player taps the screen
    Calculates distance from the sub' and determine a hit or miss */
    void takeShot(float touchX, float touchY){
        Log.d("Debugging", "In takeShot");

        // Add one to the shotsTaken variable
        player.incrementShotsTaken();

        // Convert the float screen coordinates into int grid coordinates
        player.recordShot((int) touchX / blockSize, (int) touchY / blockSize);

        // Check if shot hit the sub
        hit = horizontalTouched == submarine.getHorizontalPosition() && verticalTouched == submarine.getVerticalPosition();
        submarine.setHit(hit); // Update the submarine's hit status

        // How far away horizontally and vertically was the shot from the sub
        int horizontalGap = (int)horizontalTouched -
                submarine.getHorizontalPosition();
        int verticalGap = (int)verticalTouched -
                submarine.getVerticalPosition();

        // Use Pythagoras's theorem to get the distance travelled in a straight line
        distanceFromSub = (int)Math.sqrt(
                ((horizontalGap * horizontalGap) +
                        (verticalGap * verticalGap)));

        // If there is a hit call boom
        if(hit)
            boom();
            // Otherwise call draw as usual
        else draw();
    }

    // This code says "BOOM!"
    void boom(){

        gameView.setImageBitmap(blankBitmap);

        // Wipe the screen with a red color
        canvas.drawColor(Color.argb(255, 255, 0, 0));

        // Draw some huge white text
        paint.setColor(Color.argb(255, 255, 255, 255));
        paint.setTextSize(blockSize * 10);

        canvas.drawText("BOOM!", blockSize * 4,
                blockSize * 14, paint);

        // Draw some text to prompt restarting
        paint.setTextSize(blockSize * 2);
        canvas.drawText("Take a shot to start again",
                blockSize * 8,
                blockSize * 18, paint);

        // Start a new game
        newGame();
    }

    // This code prints the debugging text
    public void printDebuggingText(){
        paint.setTextSize(blockSize);
        canvas.drawText("numberHorizontalPixels = "
                        + numberHorizontalPixels,
                50, blockSize * 3, paint);
        canvas.drawText("numberVerticalPixels = "
                        + numberVerticalPixels,
                50, blockSize * 4, paint);
        canvas.drawText("blockSize = " + blockSize,
                50, blockSize * 5, paint);
        canvas.drawText("gridWidth = " + gridWidth,
                50, blockSize * 6, paint);
        canvas.drawText("gridHeight = " + gridHeight,
                50, blockSize * 7, paint);
        canvas.drawText("horizontalTouched = " +
                        horizontalTouched, 50,
                blockSize * 8, paint);
        canvas.drawText("verticalTouched = " +
                        verticalTouched, 50,
                blockSize * 9, paint);
        canvas.drawText("subHorizontalPosition = " +
                        submarine.getHorizontalPosition(), 50,
                blockSize * 10, paint);
        canvas.drawText("subVerticalPosition = " +
                        submarine.getVerticalPosition(), 50,
                blockSize * 11, paint);
        canvas.drawText("hit = " + hit,
                50, blockSize * 12, paint);
        canvas.drawText("shotsTaken = " +
                        player.getShotsTaken(),
                50, blockSize * 13, paint);
        canvas.drawText("debugging = " + debugging,
                50, blockSize * 14, paint);

    }
}