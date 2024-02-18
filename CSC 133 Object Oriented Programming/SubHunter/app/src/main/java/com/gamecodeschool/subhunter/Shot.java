// Shot.java

package com.gamecodeschool.subhunter;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

public class Shot implements Drawable {
    private float horizontalPosition;
    private float verticalPosition;

    public Shot(float horizontalPosition, float verticalPosition) {
        this.horizontalPosition = horizontalPosition;
        this.verticalPosition = verticalPosition;
    }

    @Override
    public void draw(Canvas canvas, Paint paint, int blockSize) {
        paint.setColor(Color.RED); // Example color for the shot
        int left = (int) horizontalPosition * blockSize;
        int top = (int) verticalPosition * blockSize;
        canvas.drawRect(left, top, left + blockSize, top + blockSize, paint);
    }
}
