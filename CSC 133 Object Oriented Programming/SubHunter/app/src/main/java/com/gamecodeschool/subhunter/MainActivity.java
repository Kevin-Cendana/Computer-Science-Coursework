/*  todo:
 *   - Add: Simplify conditional logic based on data types
 *   - Add: GameContext.java so things like Submarine can access gridWidth/Height, shots, etc,
 *      more gracefully, instead of having to pass in other parameters
 *   - Add: Debug.java mode and have it triggered with a simple flag.
 *   - Fix: Game text being drawn over GameOver
 *   - Remove (when finished): Submarine being drawn as a Drawable, have it draw only in Debug
 *   - Maybe: Rename MainActivity? Idk if this is vague
 * */
package com.gamecodeschool.subhunter;

import android.app.Activity;
import android.os.Bundle;
import android.view.Display;
import android.view.MotionEvent;
import android.graphics.Point;
import android.widget.ImageView;
import java.util.ArrayList;


public class MainActivity extends Activity {
    int numberHorizontalPixels;
    int numberVerticalPixels;
    int blockSize;
    int gridWidth = 40;
    int gridHeight;

    // Drawable Objects
    private Submarine submarine;
    private Player player;
    private Shot shot;
    private Grid grid;
    private GameOverScreen gameOverScreen;
    private ArrayList<Drawable> drawables = new ArrayList<>(); // List of objects to be drawn
    private ArrayList<Resettable> resettables= new ArrayList<>(); // List of objects to be reset on new game
    private GameView gameView; // Class that handles drawing

    // Function: Initialize the game
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // Initialize screen size variables
        Display display = getWindowManager().getDefaultDisplay();
        Point size = new Point();
        display.getSize(size);
        numberHorizontalPixels = size.x;
        numberVerticalPixels = size.y;
        blockSize = numberHorizontalPixels / gridWidth;
        gridHeight = numberVerticalPixels / blockSize;

        // Initialize drawable objects
        submarine = new Submarine(gridWidth, gridHeight);
        player = new Player();
        grid = new Grid(gridWidth, gridHeight, blockSize);
        shot = new Shot(-1, -1); // Default shot, not on screen
        gameOverScreen = new GameOverScreen();

        // Setup the GameView, the class that handles drawing
        ImageView imageView = new ImageView(this);
        gameView = new GameView(imageView, this, new ArrayList<>(),
                player, submarine, shot,
                numberHorizontalPixels, numberVerticalPixels,  blockSize);
        setContentView(imageView);

        // Add drawable objects to the drawables list
        drawables.add(grid);
        drawables.add(submarine);
        gameView.setDrawables(drawables); // Update GameView's drawable list

        // Add resettable objects to the resettable list
        resettables.add(player);
        resettables.add(submarine);
        resettables.add(shot);

        newGame();
    }

    // Function: Handle touch events
    @Override
    public boolean onTouchEvent(MotionEvent motionEvent) {
        if ((motionEvent.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_UP) {
            takeShot(motionEvent.getX(), motionEvent.getY());
        }
        return true;
    }

    // Function: Start a new game by resetting the game state
    void newGame() {
        // Reset all resettable objects (Player, Submarine, Shot, etc)
        for (Resettable resettable : resettables) {
            resettable.reset();
        }
        gameOverScreen.hide(); // Hide the game over screen
        drawables.remove(gameOverScreen); // Remove it from the drawables list
        gameView.setDrawables(drawables); // Update GameView's drawable list
        gameView.draw(); // Redraw the game view

    }

    // Function: Draw the GameView
    void draw() {
        // If the game over screen is visible, add it to the drawables list
        if (gameOverScreen.getIsVisible()) {
            if (!drawables.contains(gameOverScreen)) {
                drawables.add(gameOverScreen);
            }
        }
        // Else, remove it from the drawables list
        else {
            drawables.remove(gameOverScreen);
        }
        gameView.setDrawables(drawables);
        gameView.draw();
    }

    // Function: Take a shot at the submarine
    void takeShot(float touchX, float touchY) {
        // Before processing the shot, check if the game is over
        if (gameOverScreen.getIsVisible()) {
            newGame(); // If game is over, reset the game
            return; // Exit early so we don't process the shot as normal
        }

        // Create new Shot drawable, increment shots taken, and attempt to hit the submarine
        shot = new Shot((int) touchX / blockSize, (int) touchY / blockSize);
        player.incrementShotsTaken();
        submarine.attemptToHit(shot);

        // If the submarine is hit, end the game
        if (submarine.getIsHit()) {
            gameOver();
        } else {
            // Else add the shot, update the drawables in GameView, and redraw
            drawables.add(shot);
            draw();
            drawables.remove(shot); // Remove the shot so it's not permanently drawn
        }
    }

    // Function: End the game
    void gameOver() {
        gameOverScreen.show(); // Make sure this sets isVisible to true
        if (!drawables.contains(gameOverScreen)) {
            drawables.add(gameOverScreen);
        }
        gameView.setDrawables(drawables); // Update the drawables in GameView
        gameView.draw(); // Redraw to show the game over screen
    }


}
