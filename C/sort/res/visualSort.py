import matplotlib.pyplot as plt
import matplotlib.animation as animation
import os

def read_sort_steps(filename):
    if os.path.exists(filename):
        with open(filename, 'r') as file:
            steps = [list(map(int, line.split())) for line in file]
        return steps
    else: exit(-1);

def update(frame):
    plt.clf()
    plt.bar(range(len(steps[frame])), steps[frame])
    plt.title(f'Step {frame + 1}')

# 确保从 utils 目录中读取 sort_steps.txt 文件
steps = read_sort_steps(os.path.join('utils', 'sort_steps.txt'))

fig = plt.figure()
ani = animation.FuncAnimation(fig, update, frames=len(steps), interval=1500, repeat=False)

plt.show()
