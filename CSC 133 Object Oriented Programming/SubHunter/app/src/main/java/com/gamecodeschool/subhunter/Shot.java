// Shot.java

package com.gamecodeschool.subhunter;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

public class Shot implements Drawable {
    private int xPos;
    private int yPos;

    // Constructor
    public Shot(int xPos, int yPos) {
        this.xPos = xPos;
        this.yPos = yPos;
    }

    // Getters and Setters
    public int getXPos() { return xPos; }
    public int getYPos() { return yPos; }

    @Override
    public void draw(Canvas canvas, Paint paint, int blockSize) {
        paint.setColor(Color.RED); // Example color for the shot
        int left = (int) xPos * blockSize;
        int top = (int) yPos * blockSize;
        canvas.drawRect(left, top, left + blockSize, top + blockSize, paint);
    }
}
