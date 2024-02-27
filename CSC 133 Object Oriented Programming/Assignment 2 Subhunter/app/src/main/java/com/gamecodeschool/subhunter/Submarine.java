// Submarine.java

package com.gamecodeschool.subhunter;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

import java.util.Random; // For RNG

public class Submarine implements Drawable, Resettable {
    private int xPos; // Submarine position on grid
    private int yPos; // Submarine position on grid
    private int distanceFromShot;
    private boolean isHit; // Submarine flag for if it's hit
    private GameContext gameContext;

    // Constructor
    public Submarine(GameContext gameContext) {
        this.isHit = false;
        this.gameContext = gameContext;
    }

    // Getters and Setters
    public int getXPos() {
        return xPos;
    }
    public void setXPos(int xPos) { this.xPos = xPos; }
    public int getYPos() { return yPos; }
    public void setYPos(int yPos) { this.yPos = yPos; }
    public boolean getIsHit() { return isHit; }
    public void setIsHit(boolean hit) { this.isHit = hit;}
    public void setDistanceFromShot(int distanceFromShot) { this. distanceFromShot = distanceFromShot; }
    public int getDistanceFromShot() { return this.distanceFromShot; };

    // Function: Place the submarine on the grid randomly
    public void placeSubmarine() {
        Random random = new Random(); // RNG
        this.xPos = random.nextInt(gameContext.getGridWidth()); // Set sub width
        this.yPos = random.nextInt(gameContext.getGridHeight()); // Set sub height
    }

    // Function: Calculate the sub's distance from the shot
    public int calculateDistanceFromShot(Shot shot) {
        int horizontalGapFromShot = shot.getXPos() - this.getXPos();
        int verticalGapFromShot = shot.getYPos() - this.getYPos();
        return (int)Math.sqrt(
                ((horizontalGapFromShot * horizontalGapFromShot) +
                        (verticalGapFromShot * verticalGapFromShot)));
    }

    // Function: Check if a shot hit the sub by passing in Shot coordinates.
    public void attemptToHit(Shot shot) {
        // If the shot is the same coordinates, register sub as hit
        if(shot.getXPos() == this.getXPos() && shot.getYPos() == this.getYPos()) {
            this.setIsHit(true);
        }
        // Else, calculate the distance the shot was off and set it.
        else {
            setDistanceFromShot(calculateDistanceFromShot(shot));
        }
    }

    // Function: Draw the submarine
    @Override
    public void draw(Canvas canvas, Paint paint, int blockSize) {
        if (!isHit) {
            paint.setColor(Color.GREEN);
            int left = xPos * blockSize;
            int top = yPos * blockSize;
            canvas.drawRect(left, top, left + blockSize, top + blockSize, paint);
        }
    }

    // Function: Reset the submarine
    @Override
    public void reset() {
        this.isHit = false; // Reset hit flag
        this.distanceFromShot = 0; // Reset distance from shot
        placeSubmarine(); // Place the sub again
    }
}
