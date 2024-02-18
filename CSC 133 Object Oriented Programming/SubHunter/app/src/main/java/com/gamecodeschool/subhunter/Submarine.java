// Submarine.java

package com.gamecodeschool.subhunter;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

import java.util.Random; // For RNG

public class Submarine implements Drawable {
    private int horizontalPosition; // Submarine position on grid
    private int verticalPosition; // Submarine position on grid
    private boolean hit; // Submarine flag for if it's hit

    // Constructor
    public Submarine() {
        this.hit = false;         // Initially, not hit
    }

    // Getters and Setters
    public int getHorizontalPosition() {
        return horizontalPosition;
    }
    public void setHorizontalPosition(int horizontalPosition) { this.horizontalPosition = horizontalPosition; }
    public int getVerticalPosition() { return verticalPosition; }
    public void setVerticalPosition(int verticalPosition) { this.verticalPosition = verticalPosition; }
    public boolean isHit() { return hit; }
    public void setHit(boolean hit) { this.hit = hit;}

    // Function: Randomly place the submarine on the grid
    public void placeSubmarine(int gridWidth, int gridHeight) {
        Random random = new Random(); // RNG
        this.horizontalPosition = random.nextInt(gridWidth); // Set sub width
        this.verticalPosition = random.nextInt(gridHeight); // Set sub height
    }

    // Function: Draw the submarine
    @Override
    public void draw(Canvas canvas, Paint paint, int blockSize) {
        if (!hit) {
            paint.setColor(Color.GREEN); // Example color for the submarine
            int left = horizontalPosition * blockSize;
            int top = verticalPosition * blockSize;
            canvas.drawRect(left, top, left + blockSize, top + blockSize, paint);
        }
    }
}
