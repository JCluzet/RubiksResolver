import cube_controller
import numpy as np
import pygame
from pygame.locals import *
import copy
import sys
import glfw
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import gluPerspective
import math

pygame.init

theta_inc = 7

center_pieces = [
    
    [[-1, -1, 3],
     [-1, 1, 3],
     [1, 1, 3],
     [1, -1, 3],
     [-1, -1, 1],
     [-1, 1, 1],
     [1, 1, 1],
     [1, -1, 1]],

    [[-3, -1, 1],
     [-3, 1, 1],
     [-1, 1, 1],
     [-1, -1, 1],
     [-3, -1, -1],
     [-3, 1, -1],
     [-1, 1, -1],
     [-1, -1, -1]],

    [[-1, -1, -1],
     [-1, 1, -1],
     [1, 1, -1],
     [1, -1, -1],
     [-1, -1, -3],
     [-1, 1, -3],
     [1, 1, -3],
     [1, -1, -3],
     ],
    
    [[1, -1, 1],
     [1, 1, 1],
     [3, 1, 1],
     [3, -1, 1],
     [1, -1, -1],
     [1, 1, -1],
     [3, 1, -1],
     [3, -1, -1],
     ],

    [[-1, 1, 1],
     [-1, 3, 1],
     [1, 3, 1],
     [1, 1, 1],
     [-1, 1, -1],
     [-1, 3, -1],
     [1, 3, -1],
     [1, 1, -1]
     ],

    [[-1, -3, 1],
     [-1, -1, 1],
     [1, -1, 1],
     [1, -3, 1],
     [-1, -3, -1],
     [-1, -1, -1],
     [1, -1, -1],
     [1, -3, -1]
     ]
]

edge_pieces = [
    [[[-1, -3, 3],
      [-1, -1, 3],
      [1, -1, 3],
      [1, -3, 3],
      [-1, -3, 1],
      [-1, -1, 1],
      [1, -1, 1],
      [1, -3, 1]
      ],

     [[-1, 1, 3],
      [-1, 3, 3],
      [1, 3, 3],
      [1, 1, 3],
      [-1, 1, 1],
      [-1, 3, 1],
      [1, 3, 1],
      [1, 1, 1]
      ],

     [[-1, 1, -1],
      [-1, 3, -1],
      [1, 3, -1],
      [1, 1, -1],
      [-1, 1, -3],
      [-1, 3, -3],
      [1, 3, -3],
      [1, 1, -3]
      ],
     
     [[-1, -3, -1],
      [-1, -1, -1],
      [1, -1, -1],
      [1, -3, -1],
      [-1, -3, -3],
      [-1, -1, -3],
      [1, -1, -3],
      [1, -3, -3]]
      ],

    [[[-3, -1, 3],
      [-3, 1, 3],
      [-1, 1, 3],
      [-1, -1, 3],
      [-3, -1, 1],
      [-3, 1, 1],
      [-1, 1, 1],
      [-1, -1, 1]
      ],

     [[-3, -1, -1],
      [-3, 1, -1],
      [-1, 1, -1],
      [-1, -1, -1],
      [-3, -1, -3],
      [-3, 1, -3],
      [-1, 1, -3],
      [-1, -1, -3]
      ],

     [[1, -1, -1],
      [1, 1, -1],
      [3, 1, -1],
      [3, -1, -1],
      [1, -1, -3],
      [1, 1, -3],
      [3, 1, -3],
      [3, -1, -3]
      ],

     [[1, -1, 3],
      [1, 1, 3],
      [3, 1, 3],
      [3, -1, 3],
      [1, -1, 1],
      [1, 1, 1],
      [3, 1, 1],
      [3, -1, 1]]
      ],
    
    [[[-3, -3, 1],
      [-3, -1, 1],
      [-1, -1, 1],
      [-1, -3, 1],
      [-3, -3, -1],
      [-3, -1, -1],
      [-1, -1, -1],
      [-1, -3, -1]
      ],
     
     [[-3, 1, 1],
      [-3, 3, 1],
      [-1, 3, 1],
      [-1, 1, 1],
      [-3, 1, -1],
      [-3, 3, -1],
      [-1, 3, -1],
      [-1, 1, -1]
      ],

     [[1, 1, 1],
      [1, 3, 1],
      [3, 3, 1],
      [3, 1, 1],
      [1, 1, -1],
      [1, 3, -1],
      [3, 3, -1],
      [3, 1, -1]
      ],

     [[1, -3, 1],
      [1, -1, 1],
      [3, -1, 1],
      [3, -3, 1],
      [1, -3, -1],
      [1, -1, -1],
      [3, -1, -1],
      [3, -3, -1]]
      ],
]

corner_pieces = [
    [[-3, -3, 3],
     [-3, -1, 3],
     [-1, -1, 3],
     [-1, -3, 3],
     [-3, -3, 1],
     [-3, -1, 1],
     [-1, -1, 1],
     [-1, -3, 1]],
    
    [[-3, 1, 3],
     [-3, 3, 3],
     [-1, 3, 3],
     [-1, 1, 3],
     [-3, 1, 1],
     [-3, 3, 1],
     [-1, 3, 1],
     [-1, 1, 1]],
    
    [[1, 1, 3],
     [1, 3, 3],
     [3, 3, 3],
     [3, 1, 3],
     [1, 1, 1],
     [1, 3, 1],
     [3, 3, 1],
     [3, 1, 1]],
    
    [[1, -3, 3],
     [1, -1, 3],
     [3, -1, 3],
     [3, -3, 3],
     [1, -3, 1],
     [1, -1, 1],
     [3, -1, 1],
     [3, -3, 1]],
    
    [[-3, -3, -1],
     [-3, -1, -1],
     [-1, -1, -1],
     [-1, -3, -1],
     [-3, -3, -3],
     [-3, -1, -3],
     [-1, -1, -3],
     [-1, -3, -3]],
    
    [[-3, 1, -1],
     [-3, 3, -1],
     [-1, 3, -1],
     [-1, 1, -1],
     [-3, 1, -3],
     [-3, 3, -3],
     [-1, 3, -3],
     [-1, 1, -3]],
    
    [[1, 1, -1],
     [1, 3, -1],
     [3, 3, -1],
     [3, 1, -1],
     [1, 1, -3],
     [1, 3, -3],
     [3, 3, -3],
     [3, 1, -3]],
    
    [[1, -3, -1],
     [1, -1, -1],
     [3, -1, -1],
     [3, -3, -1],
     [1, -3, -3],
     [1, -1, -3],
     [3, -1, -3],
     [3, -3, -3]],
]

front_edges = [
    [0, 0],  
    [0, 1],
    [1, 0],  
    [1, 3]
]

left_edges = [
    [1, 0],  
    [1, 1],
    [2, 0],  
    [2, 1]
]

back_edges = [
    [0, 2],  
    [0, 3],
    [1, 1],  
    [1, 2]
]

right_edges = [
    [1, 2],  
    [1, 3],
    [2, 2],  
    [2, 3]
]

up_edges = [
    [0, 1],  
    [0, 2],
    [2, 1],  
    [2, 2]
]

down_edges = [
    [0, 0],  
    [0, 3],
    [2, 0],  
    [2, 3]
]

edges = [front_edges,
         left_edges,
         back_edges,
         right_edges,
         up_edges,
         down_edges]

cube_verts = (
    (-3.0, -3.0, 3.0),  
    (-3.0, 3.0, 3.0),  
    (3.0, 3.0, 3.0),  
    (3.0, -3.0, 3.0),  
    (-3.0, -3.0, -3.0),  
    (-3.0, 3.0, -3.0),  
    (3.0, 3.0, -3.0),  
    (3.0, -3.0, -3.0)  
)

cube_edges = (
    (0, 1),
    (0, 3),
    (0, 4),
    (2, 1),
    (2, 3),
    (2, 6),
    (5, 1),
    (5, 4),
    (5, 6),
    (7, 3),
    (7, 4),
    (7, 6)
)

cube_surfaces = (
    [0, 1, 2, 3],  
    [4, 5, 1, 0],  
    [7, 6, 5, 4],  
    [3, 2, 6, 7],  
    [1, 5, 6, 2],  
    [4, 0, 3, 7]  
)

cube_colors = [
    (0.8, 0.118, 0.118),  
    (0.0, 0.318, 0.729),  
    (1.0, 0.345, 0.0),  
    (0.0, 0.7, 0.2),  
    (1.0, 0.85, 0.1),  
    (1.0, 1.0, 1.0),  
]

pulse_color = [0.0, 0.0, 0.0]
pulse_val = 0.04

axis_verts = (
    (-7.5, 0.0, 0.0),
    (7.5, 0.0, 0.0),
    (0.0, -7.5, 0.0),
    (0.0, 7.5, 0.0),
    (0.0, 0.0, -7.5),
    (0.0, 0.0, 7.5)
)

axes = (
    (0, 1),
    (2, 3),
    (4, 5)
)

axis_colors = (
    (1.0, 0.0, 0.0),  
    (0.0, 1.0, 0.0),  
    (0.0, 0.0, 1.0)  
)

last_x, last_y = 0, 0
yaw, pitch = 0, 0
mouse_pressed = False

def x_rot(v, theta):
    x, y, z = v
    cos_theta = math.cos(theta)
    sin_theta = math.sin(theta)
    
    new_x = x
    new_y = cos_theta * y - sin_theta * z
    new_z = sin_theta * y + cos_theta * z
    
    return [new_x, new_y, new_z]

def y_rot(v, theta):
    x, y, z = v
    cos_theta = math.cos(theta)
    sin_theta = math.sin(theta)
    
    new_x = cos_theta * x + sin_theta * z
    new_y = y
    new_z = -sin_theta * x + cos_theta * z
    
    return [new_x, new_y, new_z]

def z_rot(v, theta):
    x, y, z = v
    cos_theta = math.cos(theta)
    sin_theta = math.sin(theta)
    
    new_x = cos_theta * x - sin_theta * y
    new_y = sin_theta * x + cos_theta * y
    new_z = z
    
    return [new_x, new_y, new_z]

def mouse_callback(window, x, y):
    global last_x, last_y, yaw, pitch, mouse_pressed

    if mouse_pressed:
        delta_x = x - last_x
        delta_y = y - last_y
        sensitivity = 0.1
        yaw += delta_x * sensitivity
        pitch += delta_y * sensitivity
        pitch = max(-90, min(90, pitch))
        update_camera()
    last_x, last_y = x, y

def mouse_button_callback(window, button, action, mods):
    global mouse_pressed
    if button == glfw.MOUSE_BUTTON_LEFT:
        mouse_pressed = (action == glfw.PRESS)

def update_camera():
    glLoadIdentity()
    gluPerspective(60, (800 / 600), 0.1, 50.0)
    glTranslatef(0.0, -3, -20)
    glRotatef(pitch, 1, 0, 0)
    glRotatef(yaw, 0, 1, 0)

def draw_cube():
    glLineWidth(GLfloat(6.0))
    glBegin(GL_LINES)
    glColor3fv((0.0, 0.0, 0.0))
    for axis in edge_pieces:
        for piece in axis:
            for edge in cube_edges:
                for vertex in edge:
                    glVertex3fv(piece[vertex])
    for piece in center_pieces:
        for edge in cube_edges:
            for vertex in edge:
                glVertex3fv(piece[vertex])
    for piece in corner_pieces:
        for edge in cube_edges:
            for vertex in edge:
                glVertex3fv(piece[vertex])
    glEnd()
    draw_stickers()

def draw_stickers():
    glBegin(GL_QUADS)
    i = 0
    for color, surface in zip(cube_colors, cube_surfaces):
        glColor3fv((color))
        for vertex in surface:
            glVertex3fv(center_pieces[i][vertex])
        j = 0
        for piece in center_pieces:
            glColor3fv((0, 0, 0))
            for vertex in surface:
                glVertex3fv(center_pieces[j][vertex])
            j += 1
        i += 1
    for color, surface, face in zip(cube_colors, cube_surfaces, edges):
        glColor3fv((color))
        for piece in face:
            for vertex in surface:
                glVertex3fv(edge_pieces[piece[0]][piece[1]][vertex])
    
    edge_black_pat = [
        [0, 1, 2, 3, 4, 5],
        [0, 1, 2, 3, 4, 5],
        [0, 1, 2, 3, 4, 5]
    ]

    glColor3fv((0, 0, 0))
    for i in range(len(edge_black_pat)):
        for face in edge_black_pat[i]:
            for piece in edge_pieces[i]:
                for vertex in cube_surfaces[face]:
                    glVertex3fv(piece[vertex])
    corner_color_pat = [
        [0, 1, 5],  
        [0, 1, 4],  
        [0, 3, 4],  
        [0, 3, 5],  
        [2, 1, 5],  
        [2, 1, 4],  
        [2, 3, 4],  
        [2, 3, 5],  
    ]
    corner_black_pat = [
        [2, 3, 4],  
        [2, 3, 5],  
        [2, 1, 5],  
        [2, 1, 4],  
        [0, 3, 4],  
        [0, 3, 5],  
        [0, 1, 5],  
        [0, 1, 4],  
    ]
    for i in range(len(corner_color_pat)):
        for face in corner_color_pat[i]:
            glColor3fv((cube_colors[face]))
            for vertex in cube_surfaces[face]:
                glVertex3fv(corner_pieces[i][vertex])
    glColor3fv((0, 0, 0))
    for i in range(len(corner_black_pat)):
        for face in corner_black_pat[i]:
            for vertex in cube_surfaces[face]:
                glVertex3fv(corner_pieces[i][vertex])
    glEnd()

def draw_axis():
    glLineWidth(GLfloat(1.0))
    glBegin(GL_LINES)
    for color, axis in zip(axis_colors, axes):
        glColor3fv(color)
        for point in axis:
            glVertex3fv(axis_verts[point])
    glEnd()

def display():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    update_camera()

    draw_cube()
    draw_axis()

    glfw.swap_buffers(window)

def rotate_cube(move, reverse=False):
    global theta_inc
    theta = math.pi / 2
    theta *= -1 if reverse else 1

    if move == 'F':
        for x in range(7):
            for i in range(8):
                center_pieces[0][i] = z_rot(center_pieces[0][i], theta)

            for axis in edge_pieces:
                for piece in axis:
                    flag = all(vertex[2] > 0 for vertex in piece)
                    if flag:
                        for i in range(8):
                            piece[i] = z_rot(piece[i], -theta)
            for piece in corner_pieces:
                flag = all(vertex[2] > 0 for vertex in piece)
                if flag:
                    for i in range(8):
                        piece[i] = z_rot(piece[i], -theta)

    if move =='L':
        for x in range(theta_inc):
            for i in range(8):
                center_pieces[1][i] = x_rot(center_pieces[1][i], theta)
            for axis in edge_pieces:
                for piece in axis:
                    flag = True
                    for vertex in piece:
                        if vertex[0] > 0:
                            flag = False
                            break
                    if flag:
                        for i in range(8):
                            piece[i] = x_rot(piece[i], theta)
            for piece in corner_pieces:
                flag = True
                for vertex in piece:
                    if vertex[0] > 0:
                        flag = False
                        break
                if flag:
                    for i in range(8):
                        piece[i] = x_rot(piece[i], theta)

    if move =='B':
        for x in range(theta_inc):
            for i in range(8):
                center_pieces[2][i] = z_rot(center_pieces[2][i], theta)
            for axis in edge_pieces:
                for piece in axis:
                    flag = True
                    for vertex in piece:
                        if vertex[2] > 0:
                            flag = False
                            break
                    if flag:
                        for i in range(8):
                            piece[i] = z_rot(piece[i], theta)
            for piece in corner_pieces:
                flag = True
                for vertex in piece:
                    if vertex[2] > 0:
                        flag = False
                        break
                if flag:
                    for i in range(8):
                        piece[i] = z_rot(piece[i], theta)

    if move =='R':
        for x in range(theta_inc):
            for i in range(8):
                center_pieces[3][i] = x_rot(center_pieces[3][i], theta)
            for axis in edge_pieces:
                for piece in axis:
                    flag = True
                    for vertex in piece:
                        if vertex[0] < 0:
                            flag = False
                            break
                    if flag:
                        for i in range(8):
                            piece[i] = x_rot(piece[i], theta)
            for piece in corner_pieces:
                flag = True
                for vertex in piece:
                    if vertex[0] < 0:
                        flag = False
                        break
                if flag:
                    for i in range(8):
                        piece[i] = x_rot(piece[i], theta)

    if move =='U':
        for x in range(theta_inc):
            for i in range(8):
                center_pieces[4][i] = y_rot(center_pieces[4][i], theta)
            for axis in edge_pieces:
                for piece in axis:
                    flag = True
                    for vertex in piece:
                        if vertex[1] < 0:
                            flag = False
                            break
                    if flag:
                        for i in range(8):
                            piece[i] = y_rot(piece[i], theta)
            for piece in corner_pieces:
                flag = True
                for vertex in piece:
                    if vertex[1] < 0:
                        flag = False
                        break
                if flag:
                    for i in range(8):
                        piece[i] = y_rot(piece[i], theta)

    if move =='D':
        for x in range(theta_inc):
            for i in range(8):
                center_pieces[5][i] = y_rot(center_pieces[5][i], theta)
            for axis in edge_pieces:
                for piece in axis:
                    flag = True
                    for vertex in piece:
                        if vertex[1] > 0:
                            flag = False
                            break
                    if flag:
                        for i in range(8):
                            piece[i] = y_rot(piece[i], theta)
            for piece in corner_pieces:
                flag = True
                for vertex in piece:
                    if vertex[1] > 0:
                        flag = False
                        break
                if flag:
                    for i in range(8):
                        piece[i] = y_rot(piece[i], theta)

def key_callback(window, key, scancode, action, mods):
    if action == glfw.PRESS:
        if key == glfw.KEY_F:
            rotate_cube('F')
        elif key == glfw.KEY_L:
            rotate_cube('L')
        elif key == glfw.KEY_B:
            rotate_cube('B')
        elif key == glfw.KEY_D:
            rotate_cube('D')
        elif key == glfw.KEY_U:
            rotate_cube('U')
        elif key == glfw.KEY_R:
            rotate_cube('R')

def update_cube(move):
    print(f"Received move: {move}")
    rotate_cube(move)

def main():
    global window, last_x, last_y
    cube_controller_instance = cube_controller.CubeController()
    cube_controller_instance.moveSignal.connect(update_cube)

    if not glfw.init():
        return

    width, height = 800, 600
    window = glfw.create_window(width, height, "Rubik's Cube Visualizer", None, None)

    if not window:
        glfw.terminate()
        return

    glfw.make_context_current(window)
    glEnable(GL_DEPTH_TEST)

    glfw.set_cursor_pos_callback(window, mouse_callback)
    glfw.set_mouse_button_callback(window, mouse_button_callback)
    glfw.set_key_callback(window, key_callback)

    while not glfw.window_should_close(window):
        glfw.poll_events()
        display()

    glfw.terminate()

if __name__ == "__main__":
    main()