from tkinterMini import SimpleGUI

# create the app instance
app = SimpleGUI(title="Tkinter Example", width=400, height=300)
    
def on_button_click():
    app.show_message("Button Clicked", "Hello from the button!")
    
app.add_label("Hello!", row=0, column=0)
app.add_button("Click Me", command=on_button_click, row=1, column=0)
entry = app.add_entry(row=2, column=0)
var = app.add_check_button("Check me", row=3, column=0)

def check_entry():
    if var.get() == 1:
        app.show_message("Checked", f"Text: {entry.get()}")

app.add_button("Check Entry", command=check_entry, row=4, column=0)

app.run()