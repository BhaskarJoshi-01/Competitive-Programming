#!/usr/bin/python3

import math
import pygame
from pygame.locals import *

pygame.init()
pygame.mixer.init()

width = 1000
height = 800
screen = pygame.display.set_mode((width,height))
pygame.display.set_caption('Cross The Road')

Player1 = pygame.image.load('/home/abhigyangargav/PyGame/resources/images/dude2.png')
Player1 = pygame.transform.rotate(Player1, 90)
Badger1 = pygame.image.load('/home/abhigyangargav/PyGame/resources/images/badguy.png')
Badger2 = pygame.transform.rotate(Badger1, 180)
Castle1 = pygame.image.load('/home/abhigyangargav/PyGame/resources/images/castle.png')
Castle2 = pygame.image.load('/home/abhigyangargav/PyGame/resources/images/castle.png')
Castle3 = Castle2
Castle4 = Castle2
Dude1 = pygame.image.load('/home/abhigyangargav/PyGame/resources/images/dude.png')
Dude1 = pygame.transform.rotate(Dude1, 180)
Arrow1 = pygame.image.load('/home/abhigyangargav/PyGame/resources/images/bullet.png')
bck = pygame.image.load('/home/abhigyangargav/PyGame/resources/images/Road.png')
go =  pygame.image.load('/home/abhigyangargav/PyGame/resources/images/gameover.png')
yw =  pygame.image.load('/home/abhigyangargav/PyGame/resources/images/youwin.png')

pygame.mixer.music.load('/home/abhigyangargav/PyGame/resources/audio/moonlight.wav')
pygame.mixer.music.play(-1, 0.0)
pygame.mixer.music.set_volume(1)

Px = 500
Py = 730
Bx1 = 1000
By1 = 600
Bx2 = 0
By2 = 540
Cx1 = 200
Cy1 = 660
Cx2 = 700
Cy2 = 420
Cx3 = 500
Cy3 = 10
Ax1 = 0
Ay1 = 350
Dx1 = 1000
Dy1 = 290

w = False
a = False
s = False
d = False
v2 = min(Player1.get_width(),Player1.get_height()) 
v2 = v2/2
def func(Ox,Oy,w,h):
    v1 = min(w,h)
    v1 = v1/2
    val = math.sqrt((Ox-Px)**2 + (Oy-Py)**2)
    if(abs(val) < abs(v1+v2)):
        while 1:
            screen.fill(0)
            screen.blit(go,(175,175))
            pygame.display.flip()
            for event in pygame.event.get():
                if event.type == pygame.QUIT :
                    pygame.quit()
                    exit(0)

while 1 :
    
    screen.fill((0,0,0))
    screen.blit(bck,(0,0))
    screen.blit(Castle1,(Cx1,Cy1))
    screen.blit(Castle2,(Cx2,Cy2))
    screen.blit(Player1,(Px,Py))
    screen.blit(Badger1,(Bx1,By1))
    screen.blit(Badger2,(Bx2,By2))
    screen.blit(Castle3,(Cx3,Cy3))
    screen.blit(Arrow1,(Ax1,Ay1))
    screen.blit(Dude1,(Dx1,Dy1))
    Bx1 -= 10
    Bx2 += 4
    Ax1 += 11
    Dx1 -= 7 
    pygame.display.flip()
    
    if(Bx1<=0):
        Bx1 = 1200
    if(Bx2>=1000):
        Bx2 = -80
    if(Ax1>=1000):
        Ax1 = -200
    if(Dx1<=0):
        Dx1 = 1100

    if(Py<=0):
        while 1:
            screen.fill(0)
            screen.blit(yw,(175,175))
            pygame.display.flip()
            for event in pygame.event.get():
                if event.type == pygame.QUIT :
                    pygame.quit()
                    exit(0)
                    
    func(Bx1,By1,Badger1.get_width(),Badger1.get_height())
    func(Bx2,By2,Badger2.get_width(),Badger2.get_height())
    func(Cx1,Cy1,Castle1.get_width(),Castle1.get_height())
    func(Cx2,Cy2,Castle2.get_width(),Castle2.get_height())
    func(Cx3,Cy3,Castle3.get_width(),Castle3.get_height())
    func(Ax1,Ay1,Arrow1.get_width(),Arrow1.get_height())
    func(Dx1,Dy1,Dude1.get_width(),Dude1.get_height())

    
    for event in pygame.event.get():

        if event.type == pygame.KEYDOWN :
            if event.key == K_w:
                w = True
            if event.key == K_a:
                a = True
            if event.key == K_s:
                s = True
            if event.key == K_d:
                d = True
        if event.type == pygame.KEYUP  : 
            if event.key == K_w:
                w = False         
            if event.key == K_a:
                a = False
            if event.key == K_s:
                s = False
            if event.key == K_d:
                d = False
        
        if w:
            Py -= 20
        if a:
            Px -= 20
        if s:
            Py += 20
        if d:
            Px += 20

        if event.type == pygame.QUIT :
            pygame.quit()
            exit(0)


