import matplotlib.pyplot as plt
import numpy as np
import math

x = np.random.uniform(-3,3,3)
y = np.random.uniform(-3,3,3)
r_0=0.5
def generate_points(x,y):

    # x[0],y[0] -> target x,y coordinates
    # r_0 -> obstacle radius
    # x[1], y[1] -> obs1 x,y coordinates
    # x[2], y[2] -> obs2 x,y coordinates
    d1=math.dist([x[0],y[0]],[x[1],y[1]])
    d2=math.dist([x[0],y[0]],[x[2],y[2]])
    # print(d1)
    while (d1<=r_0 or d2<=r_0):
        print("Target inside obstacle")
        x=np.random.uniform(-3,3,3)
        y=np.random.uniform(-3,3,3)
        d1=math.dist([x[0],y[0]],[x[1],y[1]])
        d2=math.dist([x[0],y[0]],[x[2],y[2]])
    # print(x,y)
    return x,y
x,y=generate_points(x,y)
#now till here obstacle and target points are generated
print("target is at: ",x[0],y[0])
print
def reward_calc(xi,yi):
    reward=0
    obs_penalty=0
    for i in range(2):
        ret=math.dist([xi,yi],[x[i+1],y[i+1]])
        if ret<=(r_0+0.1):
            obs_penalty+=5
        else:
            obs_penalty+=(1/math.exp(ret-r_0))

    # ret=math.dist([x[0],y[0]],[xi,yi]) #distance between obstacle and drone
    # if(ret<=(r_0+0.1)):
    #     obs_penalty+=10
    # else:
    #     obs_penalty+=(1/ret)
    
    pos_err=math.dist([xi,yi],[x[0],y[0]])
    reachibility_reward=0
    if(pos_err<=0.15):
        reachibility_reward=10
    else:
        reachibility_reward=(1/math.exp(pos_err))
    reachibility_reward=0
    reward=2.5+1.5*reachibility_reward-2*obs_penalty-1*pos_err
    # print(reward)
    return reward

feature_x = np.linspace(-3.0, 3.0, 1000)
feature_y = np.linspace(-3.0, 3.0, 1000)

# # Creating 2-D grid of features
[X, Y] = np.meshgrid(feature_x, feature_y)
# fig, ax = plt.subplots(1, 1)
  
Z = [[0 for i in range(1000)] for j in range(1000)]
# print(Z)
for i in range(1000):
    for j in range(1000):
        Z[i][j] = reward_calc(X[i][j], Y[i][j])
Z = np.array(Z)
# # plots filled contour plot
levels = np.arange(-5, 4, 0.01)
cs = plt.contourf(X, Y, Z, levels)
plt.plot(x[0], y[0], marker="o", markersize=1, markeredgecolor="red",markerfacecolor="black")
plt.plot(x[1], y[1], marker="o", markersize=1, markeredgecolor="blue",markerfacecolor="black")
plt.plot(x[2], y[2], marker="o", markersize=1, markeredgecolor="blue",markerfacecolor="black")

plt.colorbar(cs)

plt.show()