/*  todo:
 *   - Add: Simplify conditional logic based on data types
 *   - Add: GameContext.java so things like Submarine can access gridWidth/Height, shots, etc,
 *      more gracefully, instead of having to pass in other parameters
 *   - Add: Debug.java mode and have it triggered with a simple flag.
 *   - Fix: Game text being drawn over GameOver
 *   - Remove (when finished): Submarine being drawn as a Drawable, have it draw only in Debug

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
    GameContext gameContext; // Class that holds game variables such as screen size
    private GameView gameView; // Class that handles drawing
    private Submarine submarine;
    private Player player;
    private Shot shot;
    private Grid grid;
    private GameOverScreen gameOverScreen;
    private ArrayList<Drawable> drawables = new ArrayList<>(); // List of objects to be drawn
    private ArrayList<Resettable> resettables= new ArrayList<>(); // List of objects to be reset on new game

    // Function: Set Up the game
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        initializeGameContext(); // Initialize GameContext
        initializeGameObjects(); // Initialize game objects
        initializeGameView(); // Initialize GameView
        initializeGameLists(); // Initialize game object lists
        startNewGame();
    }

    // Function: Handle touch events
    @Override
    public boolean onTouchEvent(MotionEvent motionEvent) {
        if ((motionEvent.getAction() & MotionEvent.ACTION_MASK) == MotionEvent.ACTION_UP) {
            takeShot(motionEvent.getX(), motionEvent.getY());
        }
        return true;
    }

    // Function: Initialize GameContext, the class that holds game variables
    private void initializeGameContext() {
        // Initialize screen size variables
        Display display = getWindowManager().getDefaultDisplay();
        Point size = new Point();
        display.getSize(size);
        int numberHorizontalPixels = size.x;
        int numberVerticalPixels = size.y;

        // Create a new GameContext object
        gameContext = new GameContext(numberHorizontalPixels, numberVerticalPixels);
        gameContext.logGameContext(); // Log the GameContext variables
    }

    // Function: Initialize the GameView, the class that handles drawing
    private void initializeGameView() {
        ImageView imageView = new ImageView(this);
        gameView = new GameView(imageView, this, new ArrayList<>(),
                player, submarine, shot,
                gameContext);
        setContentView(imageView);
    }

    // Function: Initialize game objects, such as the submarine, player, and grid
    private void initializeGameObjects() {
        submarine = new Submarine(gameContext);
        player = new Player();
        grid = new Grid(gameContext);
        shot = new Shot(); // Default shot, not on screen
        gameOverScreen = new GameOverScreen();
    }

    // Function: Initialize game object lists, such as Resettable and Drawable objects
    private void initializeGameLists() {
        drawables.add(grid);
        if (Debug.getDebugMode()) { // If debug mode is on, draw the submarine
            drawables.add(submarine);
        }
        gameView.setDrawables(drawables); // Update GameView's drawable list
        resettables.add(player);
        resettables.add(submarine);
        resettables.add(shot);
    }

    // Function: Start a new game by resetting the game state
    private void startNewGame() {
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
    private void draw() {
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
    private void takeShot(float touchX, float touchY) {
        // Before processing the shot, check if the game is over
        if (gameOverScreen.getIsVisible()) {
            startNewGame(); // If game is over, reset the game
            return; // Exit early so we don't process the shot as normal
        }

        // Create new Shot drawable, increment shots taken, and attempt to hit the submarine
        shot = new Shot((int) touchX / gameContext.getBlockSize(), (int) touchY / gameContext.getBlockSize());
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
        Debug.logGameContext(gameContext); // Log the GameContext variables
    }

    // Function: End the game
    private void gameOver() {
        gameOverScreen.show(); // Make sure this sets isVisible to true
        if (!drawables.contains(gameOverScreen)) {
            drawables.add(gameOverScreen);
        }
        gameView.setDrawables(drawables); // Update the drawables in GameView
        gameView.draw(); // Redraw to show the game over screen
    }

}
