// Player.java

package com.gamecodeschool.subhunter;

public class Player implements Resettable {
    private int shotsTaken;

    // Constructor
    public Player() {
        this.shotsTaken = 0;
    }

    // Getters and Setters
    public int getShotsTaken() {return shotsTaken;}
    public void setShotsTaken(int shotsTaken) {this.shotsTaken = shotsTaken;}

    // Functions: Reset shots taken, increment shots taken
    public void resetShotsTaken() { this.shotsTaken = 0;}
    public void incrementShotsTaken() { this.shotsTaken++;}

    // Function: Reset all player stats (Only shots for now, but nice to have for future updates)
    @Override
    public void reset() {
        this.shotsTaken = 0; // Reset shots taken
    }

}
