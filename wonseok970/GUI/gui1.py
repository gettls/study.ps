import tkinter as tk

window = tk.Tk()


def CtoF():
    val = int(e2.get()) * 9 / 5 + 32
    e1.delete(0, 10)
    e1.insert(0, str(val))


def FtoC():
    val = (int(e1.get()) - 32) * 5 / 9
    e2.delete(0, 10)
    e2.insert(0, str(val))


lb1 = tk.Label(window, text='Fahrenheit')
e1 = tk.Entry(window)
lb1.grid(row=0, column=0)
e1.grid(row=0, column=1)

lb2 = tk.Label(window, text='Celcius')
e2 = tk.Entry(window)
lb2.grid(row=1, column=0)
e2.grid(row=1, column=1)

bn1 = tk.Button(window, text=' Celcius -> Fahrenheit ', command=CtoF)
bn1.grid(row=2, column=0)
bn2 = tk.Button(window, text=' Fahrenheit -> Celcius ', command=FtoC)
bn2.grid(row=2, column=1)
window.mainloop()
