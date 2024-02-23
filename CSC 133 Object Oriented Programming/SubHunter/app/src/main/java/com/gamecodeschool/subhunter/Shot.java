// Shot.java

package com.gamecodeschool.subhunter;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

public class Shot implements Drawable, Resettable {
    private int xPos;
    private int yPos;

    // Constructor: Takes in the x and y position of the shot. If no position is given, set to -1.
    public Shot(int xPos, int yPos) {
        this.xPos = xPos;
        this.yPos = yPos;
    }
    public Shot() {
        this.xPos = -1; // Default shot, not on screen
        this.yPos = -1; // Default shot, not on screen
    }

    // Getters and Setters
    public int getXPos() { return xPos; }
    public int getYPos() { return yPos; }

    // Function: Draw the shot
    @Override
    public void draw(Canvas canvas, Paint paint, int blockSize) {
        paint.setColor(Color.RED); // Example color for the shot
        int left = (int) xPos * blockSize;
        int top = (int) yPos * blockSize;
        canvas.drawRect(left, top, left + blockSize, top + blockSize, paint);
    }

    // Function: Reset the shot's position
    @Override
    public void reset() {
        this.xPos = -1; // Reset shot position
        this.yPos = -1; // Reset shot position
    }
}
