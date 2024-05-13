import os
import time
import tkinter as tk
from tkinter import scrolledtext, simpledialog, messagebox

# Function: Open the calculator based on the operating system
def open_calculator():
    if os.name == 'posix':
        os.system('open -a Calculator')
    else:
        os.system('calc')

def simulate_install():
    root = tk.Tk()
    root.title("NPM Install Simulation")
    text_widget = scrolledtext.ScrolledText(root, height=15, width=50)
    text_widget.pack()
    text_widget_insert(text_widget, "Installing cool stuff...\n")
    text_widget_insert(text_widget, "Downloading packages...\n")
    text_widget_insert(text_widget, "Compiling code...\n")
    text_widget_insert(text_widget, "Success!\n")

def simulate_malicious_install():
    # Create a new top-level root window for the whole application
    root = tk.Tk()
    root.title("Hacking Simulation")

    # Create a text widget to display ASCII art and messages
    ascii_art = """
      __
 _   / /
(_) | | 
 _  | | 
(_) | | 
     \_\
     
Uh oh! You just got pwned!
"""

    # Create a single popup window for ASCII art and messages
    text_widget = scrolledtext.ScrolledText(root, height=15, width=50)
    text_widget.pack()
    time.sleep(1) 

    # Print messages and ASCII art with delays
    text_widget_insert(text_widget, ascii_art, 1)
    text_widget_insert(text_widget, "Sending all your passwords to our database...\n")
    text_widget_insert(text_widget, "Stealing all your data...\n")
    text_widget_insert(text_widget, "Sending your internet history to your mom...\n")
    text_widget_insert(text_widget, "Leaking that photo of you from Kyle's party...\n")
    text_widget_insert(text_widget, "Opening your calculator (just to show that we can)...\n")
    open_calculator()
    text_widget.config(state='disabled')  # Make the text widget read-only

# Function: Insert text into a text widget with a delay
def text_widget_insert(text_widget, message, delay=2.2):
    text_widget.insert(tk.END, message)
    text_widget.update()
    time.sleep(delay)

# Function: Simulate npm install with a GUI
def simulate_npm_install():
    root = tk.Tk()
    root.withdraw()  # Hide the main window

    while True:
        dialog = "This app simulates using a terminal and how a simple typo using npm can result in a virus due to it's open source nature.\nType 'npm install legitpackage' to simulate a normal download.\nType 'npm install legitpackagw' to simulate a malicious download."
        user_input = simpledialog.askstring("Terminal Simulator", dialog)
        if user_input is None or user_input.strip().lower() == 'exit':
            return
        elif user_input.strip() == "npm install legitpackage":
            simulate_install()
            messagebox.showinfo("Result", "Legit Package installed. (simulated)")
        elif user_input.strip() == "npm install legitpackagw":  # Typo detected
            simulate_malicious_install()  # Show messages and ASCII art in the same window
        else:
            messagebox.showinfo("Result", "No such package found. (simulated)")
            root.destroy()

    root.mainloop()

# Main function
if __name__ == "__main__":
    simulate_npm_install()
