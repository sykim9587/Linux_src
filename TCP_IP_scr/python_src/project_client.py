import socket
import time
import tkinter as Tkinter

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#192.168.0.3

def func1():
    message = "LED_OON"
    client_socket.send(message.encode())
def func2():
    message = "LED_OFF"
    client_socket.send(message.encode())
def func3():
    message = "QUIT"
    client_socket.send(message.encode())
    client_socket.close()
    
def connect():
    HOST = num_host.get()
    PORT = int(num_ip.get())
    print(HOST)
    print(PORT)    
    client_socket.connect((HOST,PORT))
    
def func4():
    message = "COUNT_S"
    client_socket.send(message.encode())

def func5():
    message = "RESET_S"
    client_socket.send(message.encode())
    

    

root1 = Tkinter.Tk() #creating a window object
root1.title("LED control and Stopwatch")
root1.config(bg='#00FF00') #colour code RGB
root1.geometry('250x250')



num_host = Tkinter.StringVar()
num_ip = Tkinter.StringVar()

lab1 = Tkinter.Label(root1,text = "IP address").place(x=10,y=10)
Host_entry1 = Tkinter.Entry(root1, textvariable=num_host).place(x=80,y=10)
lab2 = Tkinter.Label(root1,text = "Port number").place(x=10,y=50)
Host_entry2 = Tkinter.Entry(root1, textvariable=num_ip).place(x=80,y=50)


button4 = Tkinter.Button(root1, text = 'connect', command=connect).place(x=10, y=80)

button1 = Tkinter.Button(root1, text = 'ON', height = 1, width = 5, command=func1).place(x=10,y=150)
button2 = Tkinter.Button(root1, text = 'OFF', height = 1, width = 5, command=func2).place(x=90,y=150)
button3 = Tkinter.Button(root1, text = 'CUT', height = 1, width = 5, command=func3).place(x=170,y=150)

button5 = Tkinter.Button(root1, text = 'Start/Stop', height = 1, width = 10, command=func4).place(x=10,y=200)
button6 = Tkinter.Button(root1, text = 'Reset', height = 1, width = 5, command=func5).place(x=170,y=200)

root1.mainloop() #keep showing this root - exit by closing the window