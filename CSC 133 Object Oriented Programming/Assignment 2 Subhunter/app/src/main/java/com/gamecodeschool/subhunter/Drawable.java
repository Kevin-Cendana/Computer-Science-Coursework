// Drawable.java
// Interface for anything that can be drawn.

package com.gamecodeschool.subhunter;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Color;

public interface Drawable {
    void draw(Canvas canvas, Paint paint, int blockSize);
}
