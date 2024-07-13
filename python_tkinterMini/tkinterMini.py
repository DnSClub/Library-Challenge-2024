import tkinter as tk
from tkinter import messagebox

class SimpleGUI:
    
    # create a window with a specified title and size
    def __init__(self, title="Simple GUI", width=300, height=200):
        self.root = tk.Tk()
        self.root.title(title)
        self.root.geometry(f"{width}x{height}")
    
    # labels to the window
    def add_label(self, text, row, column):
        label = tk.Label(self.root, text=text)
        label.grid(row=row, column=column)

    # buttons to the window and handle button clicks
    def add_button(self, text, command, row, column):
        button = tk.Button(self.root, text=text, command=command)
        button.grid(row=row, column=column)

    # text entry fields
    def add_entry(self, row, column):
        entry = tk.Entry(self.root)
        entry.grid(row=row, column=column)
        return entry
    
    # checkmark buttons
    def add_check_button(self, text, row, column):
        var = tk.IntVar()
        check_button = tk.Checkbutton(self.root, text=text, variable=var)
        check_button.grid(row=row, column=column)
        return var
    
    # display message boxes
    def show_message(self, title, message):
        messagebox.showinfo(title, message)
    
    def run(self):
        self.root.mainloop()