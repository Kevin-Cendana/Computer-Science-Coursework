// Debug.java
// If enabled, prints debug information to the console, such as all the GameContext variables.

package com.gamecodeschool.subhunter;

public class Debug {
    private static boolean debugMode = false;

    // Getters and Setters
    public static void setDebugMode(boolean mode) { debugMode = mode;}
    public static boolean getDebugMode() { return debugMode;}

    // Function: Log a generic message
    public static void log(String message) {
        if (debugMode) {
            System.out.println(message);
        }
    }

   // Function: Log the GameContext variables
    public static void logGameContext(GameContext gameContext) {
        if (!debugMode) return;
        log("GameContext Variables:");
        log("Number of Horizontal Pixels: " + gameContext.getNumberHorizontalPixels());
        log("Number of Vertical Pixels: " + gameContext.getNumberVerticalPixels());
        log("Block Size: " + gameContext.getBlockSize());
        log("Grid Height: " + gameContext.getGridHeight());
        log("Grid Width: " + gameContext.getGridWidth());
    }

    // Add more methods as needed for different types of debug information
}

