import random
from itertools import count
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

plt.style.use('fivethirtyeight')

x_vals = []
y_vals = []

index = count()


def animate(i):
    data = pd.read_csv('data.csv')
    x = data['x_value']
    y1 = data['total_1']

    x = x[-500:]
    y1 = y1[-500:]
    
    plt.cla()

    plt.plot(x, y1, label='Channel 1')
    
    plt.legend(loc='upper left')
    plt.tight_layout()
    plt.plot(x, y1, color='purple', linewidth=0.25)

ani = FuncAnimation(plt.gcf(), animate, interval=3)

plt.tight_layout()
plt.show()
