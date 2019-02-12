#include <kipr/botball.h>
void go_forward(int distance);
void turn_left(int degrees);
void turn_right(int degrees);
void go_backward(int distance);
void open_claw(int degrees);
void close_claw(int degrees);
void lift_claw(int distance);
int main()
{
    create_connect();
    go_forward(12);
    turn_left(90);
    create_disconnect();
    return 0;
}
void go_forward(int distance)
{ 
    set_create_distance(0);
	while(abs(get_create_distance())<distance*.705)
		{
		create_drive_direct(100,100);
		msleep(10);
		}
}
void turn_left(int degrees)
{
    set_create_total_angle(0);
    while(abs(get_create_total_angle())<degrees*.433)
    {
        create_drive_direct(-100,140);
        msleep(10);
    }
}
void turn_right(int degrees)
{
    set_create_total_angle(0);
    while(abs(get_create_total_angle())<degrees*.4)
    {
        create_drive_direct(100,-140);
        msleep(10);
    }
}
void go_backward(int distance)
{ 
    set_create_distance(0);
	while(abs(get_create_distance())<distance*.699)
		{
        
		create_drive_direct(-105,-125);
		msleep(10);
		}
}
void open_claw(int degrees)
{
    enable_servos();
    set_servo_position(0,degrees*10);
    disable_servos();
}
void close_claw(int degrees)
{
    enable_servos();
    set_servo_position(0,degrees*10);
    msleep(500);
    disable_servos();
}
void lift_claw(int distance)
{
    cmpc(0);
    while(gmpc(0)<1600)
    {
    	mav(0,500);
   		msleep(10);
    }
}
   



    
    
    
    