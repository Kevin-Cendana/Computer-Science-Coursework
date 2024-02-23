package com.gamecodeschool.subhunter;

public class GameContext {
    static final int gridWidth = 40;
    int gridHeight;
    int numberHorizontalPixels;
    int numberVerticalPixels;
    int blockSize;
    boolean isGameOver = false;

    public GameContext(int numberHorizontalPixels, int numberVerticalPixels) {
        this.numberHorizontalPixels = numberHorizontalPixels;
        this.numberVerticalPixels = numberVerticalPixels;
        this.blockSize = numberHorizontalPixels / gridWidth;
        this.gridHeight = numberVerticalPixels / blockSize;
    }

    // Getters and Setters
    public int getNumberHorizontalPixels() { return numberHorizontalPixels;}
    public int getNumberVerticalPixels() { return numberVerticalPixels;}
    public int getBlockSize() { return blockSize;}
    public int getGridHeight() { return gridHeight;}
    public int getGridWidth() { return gridWidth;}
    public boolean getIsGameOver() { return isGameOver;}
    public void setIsGameOver(boolean isGameOver) { this.isGameOver = isGameOver;}

    // Function: Log all GameContext variables
    public void logGameContext() {
        System.out.println("Number Horizontal Pixels: " + numberHorizontalPixels);
        System.out.println("Number Vertical Pixels: " + numberVerticalPixels);
        System.out.println("Block Size: " + blockSize);
        System.out.println("Grid Height: " + gridHeight);
        System.out.println("Grid Width: " + gridWidth);
    }
}
