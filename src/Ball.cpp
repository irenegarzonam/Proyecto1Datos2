#include "Ball.h"
#include "Player.h"
#include "Input.h"

Circle* Ball::ball;
Vector2 Ball::Velocity;

void Ball::PlaceBall() {

    player_rect = Player::GetPlayerRect();
    this->ball = GetCircle(); //Consigue figura del circulo para bola

    locked = true;
    speed_changed = false; //Para acelerar la bola

    PlaceCircle(Vector2(ball->x = player_rect->x + player_rect->w / 2, ball->y = player_rect->y - 16), 14); //place ball ontop of the paddle
    BallParticles.Spawn(16, ball->x, ball->y, 5, 5, true, 300); //prepare particles

    this->Player_Lives.LoadToText("Moonrising.ttf", 48, Player::GetLives(), Colors::GREEN);

    Vx = 7;
    Vy = -7;
}

void Ball::Update() {
    int score = Player::GetScore();

    if (score >= 30 && speed_changed == false) {
        Vx = 9;
        Vy = -9;

        speed_changed = true;
    }

    if (locked) {
        ball->x = player_rect->x + player_rect->w / 2; //pone la bola en el centro de la  paddle
        ball->y = player_rect->y - 16;
    }

    if (Input::Keydown(SDL_SCANCODE_SPACE)) {
        locked = false;
    }

    if (!locked) {
        MoveCircle(Vector2(Vx, Vy));
        ball = GetCircle(); //posicion de la bola actual
    }

    //===================Colision=========================//
    if (ball->x + ball->radius >= 580) { //Lado derecho
        ball->x = 580 - ball->radius;
        wall_hit_sfx.PlaySFX("wall.wav", 0, -1);

        Vx *= -1; //reverse X speed
    }

    if (ball->x - ball->radius <= 0) { //Lado izquierdo
        ball->x = 0 + ball->radius;
        wall_hit_sfx.PlaySFX("wall.wav", 0, -1);

        Velocity.x *= -1;
    }

    if (ball->y - ball->radius <= 0) { //top
        ball->y = 0 + ball->radius;
        wall_hit_sfx.PlaySFX("wall.wav", 0, -1);

        Velocity.y *= -1;
    }

    if (ball->y + ball->radius >= 600) { //bottom
        locked = true; //pone la bola de vuelta en paddle
        Vy *= -1;

        int lives = Player::GetLives();

        lives -= 1;
        Player::SetLives(lives);

        Player_Lives.ChangeToText(lives, Colors::GREEN);
    }

    Player_Lives.DrawText(660, 110);

    //=======================Collision Jugador======================//
    if (CircleToRectCollision(ball, player_rect) && !locked) { //si la bola toca el paddle rebota
        Vy *= -1;

        paddle_hit_sfx.PlaySFX("paddle.wav", 0, -1);

        if (ball->x >= player_rect->x - player_rect->w && ball->x <= player_rect->x + 30) {
            Vx = -7; //si le pega a la esquina izquierda del paddle entonces aumenta la velocidad
            if (speed_changed) {
                Vx = -9;
            }
        }

        if (ball->x >= player_rect->x + 31 && ball->x <= player_rect->x + player_rect->w / 2) {
            Vx = -4;
        }

        if (ball->x >= player_rect->x + 61 && ball->x <= player_rect->x + 90) {
            Vx = 4;
        }

        if (ball->x >= player_rect->x + player_rect->w - 30 && ball->x <= player_rect->x + player_rect->w) {
            Vx= 7; //si le pega a la esquina derecha del paddle acelera.
            if (speed_changed) {
                Vx = 9;
            }
        }

    }
    //=============================================================//
}

void Ball::Render() {
    DrawCircle(0, 255, 255, 255);
}

void Ball::Clean() {
    this->Player_Lives.FreeFont();
    this->paddle_hit_sfx.FreeSFX();
    this->wall_hit_sfx.FreeSFX();
}

int Ball::GetXSpeed() {
    return Vx;
}

int Ball::GetYSpeed() {
    return Vy;
}

void Ball::SetXSpeed(int vel) {
    Vx = vel;
}

void Ball::SetYSpeed(int vel) {
    Vy = vel;
}

Circle* Ball::GetBallCircle() {
    return ball;
}