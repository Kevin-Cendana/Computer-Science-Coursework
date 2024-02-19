/* A2 Summary
 * - The old code had functions for: starting a new game, drawing, taking a shot, hit detection, & debugging.
 * - Steps taken to create new, refactored code:
 *   - Create classes for Submarine, Player.
 *   - Create interface /  abstract class for Drawable entities (Player, Submarine, Grid)
 *   - Apply encapsulation (private classes, getters/setters)
 *  todo:
 *   - Consolidate code into GameLogic / GameView based on if it's for drawing or logic
 *   - Apply polymorphism: simplify conditional logic based on data types
 *   - Break down long functions (ex. Draw everything in a loop)
 *   - Fix the draw for loop around line 110
 * */
package com.gamecodeschool.subhunter;

import android.app.Activity;
import android.os.Bundle;
import android.view.Display;
import android.view.MotionEvent;
import android.graphics.Point;
import android.widget.ImageView;
import java.util.ArrayList;
import java.util.Random;

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

    // GameView instead of direct drawing
    private GameView gameView;

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
        gameOverScreen = new GameOverScreen();

        // Setup the GameView, the class that handles drawing
        ImageView imageView = new ImageView(this);
        gameView = new GameView(imageView, this, new ArrayList<>(),
                player, submarine, shot,
                numberHorizontalPixels, numberVerticalPixels,  blockSize);
        setContentView(imageView);

        // Now add drawables
        drawables.add(grid);
        drawables.add(submarine);
        gameView.setDrawables(drawables); // Update GameView's drawable list

        newGame();
    }


    // Function: Start a new game by resetting the game state
    void newGame() {
        player.reset();
        submarine.reset();
        shot = new Shot(-1, -1); // Default shot, not on screen
        gameOverScreen.hide(); // Hide the game over screen
        drawables.remove(gameOverScreen); // Remove it from the drawables list
        gameView.setDrawables(drawables); // Update GameView's drawable list
        gameView.draw(); // Redraw the game view

    }


    void draw() {
        if (gameOverScreen.getIsVisible()) {
            if (!drawables.contains(gameOverScreen)) {
                drawables.add(gameOverScreen);
            }
        } else {
            drawables.remove(gameOverScreen);
        }
        gameView.setDrawables(drawables);
        gameView.draw();
    }

    @Override
    public boolean onTouchEvent(MotionEvent motionEvent) {
        if ((motionEvent.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_UP) {
            takeShot(motionEvent.getX(), motionEvent.getY());
        }
        return true;
    }

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

        if (submarine.getIsHit()) {
            gameOver();
        } else {
            // Add the shot, update the drawables in GameView, and redraw
            drawables.add(shot);
            draw();
            drawables.remove(shot); // Remove the shot so it's not permanently drawn
        }
    }

    void gameOver() {
        gameOverScreen.show(); // Make sure this sets isVisible to true
        if (!drawables.contains(gameOverScreen)) {
            drawables.add(gameOverScreen);
        }
        gameView.setDrawables(drawables); // Update the drawables in GameView
        gameView.draw(); // Redraw to show the game over screen
    }


}
