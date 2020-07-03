import socket
import time
import tkinter as Tkinter



root1 = Tkinter.Tk() #creating a window object
root1.title("LED control")
root1.config(bg='#00FF00') #colour code RGB
root1.geometry('300x300')
label1 = Tkinter.Label(root1, text = 'Press button for LED0') #create label
label1.pack() #showing the label

Host_entry = Tkinter.Entry(root1)
Host_entry.pack()
print(Host_entry.get())
root1.mainloop() #keep showing this root - exit by closing the