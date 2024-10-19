from turtle import Screen, Turtle
from paddle import Paddle, Boundary
from ball import Ball
from scoreboard import Scoreboard
import time

# Create the main turtle and screen
turtle = Turtle()
screen = Screen()

# Get user input for how many points to play until
while True:
    points = screen.textinput(prompt="Kitne Points ka Khelega?", title="Batao bhaiii")
    if points is not None and points.isdigit():
        points = int(points)
        break
    else:
        print("Invalid input. Please enter a valid number of points.")

# Set up the screen
screen.bgcolor("black")
screen.setup(width=800, height=600)
screen.title("Pong")
screen.tracer(0)

# Create paddles, ball, scoreboard, and boundary
paddle = Boundary()
paddle.boundary()

ball = Ball()
scoreboard = Scoreboard()

r_paddle = Paddle((350, 0))
l_paddle = Paddle((-350, 0))

# Listen for paddle movement keys
screen.listen()
screen.onkey(r_paddle.go_up, "Up")
screen.onkey(r_paddle.go_down, "Down")
screen.onkey(l_paddle.go_up, "w")
screen.onkey(l_paddle.go_down, "s")

# Game loop
is_game_on = True
while is_game_on:
    time.sleep(0.05)
    screen.update()
    ball.move()

    # Check if either player has won
    if scoreboard.l_score >= points or scoreboard.r_score >= points:
        is_game_on = False
        turtle.color("white")
        turtle.hideturtle()
        turtle.write("Game Over", align="center", font=("Courier", 80, "normal"))

    # Detect collision with the wall
    if ball.ycor() > 280 or ball.ycor() < -280:
        ball.bounce_y()

    # Detect collision with the paddles
    if (ball.distance(r_paddle) < 50 and ball.xcor() > 320) or (ball.distance(l_paddle) < 50 and ball.xcor() < -320):
        ball.bounce_x()

    # Detect if right paddle misses
    if ball.xcor() > 380:
        ball.reset_position()
        scoreboard.l_point()

    # Detect if left paddle misses
    if ball.xcor() < -380:
        ball.reset_position()
        scoreboard.r_point()

screen.exit
