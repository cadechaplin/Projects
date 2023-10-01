import pygame
import time
import random




pygame.init()

legal = True
x_length = 500
y_length = 500
screen = pygame.display.set_mode((x_length, y_length))
clock = pygame.time.Clock()
running = True
player = pygame.Rect(((y_length/25)*12,(x_length/25)*12,x_length/25,x_length/25))
tail = []
tail_m = []
direction = None
score = 0
i,j = 0,0
timeinc = 1
difficulty = 100
munch_count = 5
snacks = []
while i < munch_count:
    snacks.append(pygame.Rect((random.randint(1,24)*y_length/25 ,random.randint(1,24)*x_length/25 ,x_length/50,x_length/50)))
    i+=1
i = 0
gamearr = [[None]*25]*25
collision = False
go = False
'''
while i < 25:#up
    j = 0
    while j < 25:#down
        gamearr[i][j] = pygame.Rect(((x_length/25)*i,(y_length/25)*j,x_length/25,x_length/25))
        #print("i", (x_length/25)*i, "j", (x_length/25)*j)
        j+=1
    i+=1
'''
while running:
    # poll for events
    # pygame.QUIT event means the user clicked X to close your window
    screen.fill("black")
    col = (150,0,0)
    i = 0
    '''
    while i < 25:#up
        j=0
        while j < 25:#down

            pygame.draw.rect(screen,(125,0,0),gamearr[i][j])#numbers are color
            
            j += 1
        i += 1
    '''


    for snack in snacks:
        print(snack)
        if player.colliderect(snack):

            score += 1
            print(x,y)
            tail.insert(0,player.copy())
            print(tail)
            collision = True
            for item in tail:

                if player.colliderect(snack) or snack.colliderect():
                    x = random.randint(1,24)*x_length/25
                    y = random.randint(1,24)*y_length/25
                    snack.topright = (x,y)
                    
        pygame.draw.rect(screen,col,player)
    for snack in snacks:
        pygame.draw.rect(screen,(0,150,0),snack)
    key = pygame.key.get_pressed()
    for item in tail:
        pygame.draw.rect(screen,col,item)#drawing tail
    if pygame.time.get_ticks() - timeinc * difficulty > difficulty:
        timeinc += 1

        if direction == "a":
            player.move_ip(-1*(x_length/25),0)
            if player.bottomleft[0] < 0:
                go = True
        if direction == "d" :
            player.move_ip((x_length/25),0)
            if player.topright[0] > x_length:
                go = True
        if direction == "s":
            player.move_ip(0,(y_length/25))
            if player.bottomleft[1] > y_length:
                go = True
        if direction == "w":
            player.move_ip(0,-1*(y_length/25))
            if player.topright[1] < 0:
                go = True

        if collision == True:
            first = 1
        else:
            first = 0
        while first < len(tail):
            if player.colliderect(tail[first]):
                go = True
            first += 1
        tail_m.insert(0,direction)
        if len(tail_m) -1 > score:
            tail_m.pop()
        tail_p = len(tail)-1
        if collision == False:
            while tail_p >= 0:
                if tail_m[tail_p+1] == "a" :
                    tail[tail_p].move_ip(-1*(x_length/25),0)
                if tail_m[tail_p+1] == "d":
                    tail[tail_p].move_ip((x_length/25),0)
                if tail_m[tail_p+1] == "s":
                    tail[tail_p].move_ip(0,(y_length/25))
                if tail_m[tail_p+1] == "w":
                    tail[tail_p].move_ip(0,-1*(y_length/25))
                tail_p -= 1
        else:
            collision = False



    if key[pygame.K_a]:
        direction = "a"
    if key[pygame.K_d]:
        direction = "d"
    if key[pygame.K_s]:
        direction = "s"
    if key[pygame.K_w]:
        direction = "w"


    pygame.display.update()
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    if go:
        start = pygame.time.get_ticks()
        count = 0
        col = "white"

        while count < 7:

            pygame.draw.rect(screen,col,player)
            for item in tail:
                pygame.draw.rect(screen,col,item)#drawing tail
            pygame.display.update()
            if pygame.time.get_ticks() - start > 500:
                if col == "white":
                    col = (150,0,0)
                else:
                    col = "white"
                count += 1
                start = pygame.time.get_ticks()
        running = False
    # fill the screen with a color to wipe away anything from last frame


    # RENDER YOUR GAME HERE

    # flip() the display to put your work on screen



    clock.tick(60)  # limits FPS to 60

pygame.quit()
