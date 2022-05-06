#include <Mbedsetting.h>
#include "segment.h"
#include <cstdio>
#include <cstdlib>
#include <iterator>
#include "Music.h"
Thread thread_segment;
Thread thread_music;
Segment segment;
N5110 lcd(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
InterruptIn buttonA(PC_5);
Joystick joystick(PC_3, PC_2,PA_5);  //attach and create joystick object
AnalogIn pot1(PA_7);
MMA8452 mma8452(PB_14,PB_13);  // SDA, SCL
Music music;
void menu_setting();
void buttonA_isr();
volatile int g_buttonA_flag = 0;
void setting_content(float set_contrast,float set_bright);
void game(matrix block );
#define monster_move_speed  0.1
int num_loop = 0;
int *num_loop_pointer = &num_loop;
void init();
void segment_module();
void run(matrix *multiblock,matrix *two_leg,matrix *two_legs,float height,int num_block,int *life,matrix *monster_head1, matrix *monster_body1);
int mode = 1;
int *pointer_mode = &mode;
int state = 0;
int health = 9;
int *life = &health;
return_monster monster_move(Map *map, matrix *two_leg ,coordinate player,coordinate Monster,matrix *monster_head1, matrix *monster_body1);
void game(matrix block);
void draw(matrix blocks);
int collisition_detect(Map *map,coordinate object);
    Map *map = new Map[40];
#define UP 0
#define DOWN 1
#define HOLD -1
int direction = UP;
struct State {
    int y_menu;  // bold at which position
    int x_menu;  // decide to choose which function
    int next_state[2]; // next state (depending on direction 0 - UP, 1 - DOWN)
};
State gamemenu[4] = 
{
    {18,70,{1,2}},
    {27,70,{2,0}},
    {35,70,{0,1}},
};
void menu();
// inital several value
matrix block =     {{-0.25f, -0.25f, 0.25f}, //8 cube vertices
                     {0.25f, -0.25f, 0.25f},
                     {0.25f, 0.25f, 0.25f},
                     {-0.25f, 0.25f, 0.25f},
                     {-0.25f, -0.25f, -0.25f},
                     {0.25f, -0.25f, -0.25f},
                     {0.25f, 0.25f, -0.25f},
                     {-0.25f, 0.25f, -0.25f},
                     {0.0f, 0.0f, 0.0f}
};

    matrix monster_leg = {{-0.05f, -0.05f, 0.15f}, //8 cube vertices
                     {0.05f, -0.05f, 0.15f},
                     {0.05f, 0.05f, 0.15f},
                     {-0.05f, 0.05f, 0.15f},
                     {-0.05f, -0.05f, -0.15f},
                     {0.05f, -0.05f, -0.15f},
                     {0.05f, 0.05f, -0.15f},
                     {-0.05f, 0.05f, -0.15f},
                     {0.0f, 0.0f, 0.0f}
    

    }; //problem of ambiguous 
        matrix monster_body = {{-0.15f, -0.1f, 0.1f}, //8 cube vertices
                     {0.15f, -0.1f, 0.1f},
                     {0.15f, 0.1f, 0.1f},
                     {-0.15f, 0.1f, 0.1f},
                     {-0.15f, -0.1f, -0.1f},
                     {0.15f, -0.1f, -0.1f},
                     {0.15f, 0.1f, -0.1f},
                     {-0.15f, 0.1f, -0.1f},
                     {0.0f, 0.0f, 0.0f}
    

    }; //problem of ambiguous 
        matrix monster_head = {{-0.1f, -0.1f, 0.1f}, //8 cube vertices
                     {0.1f, -0.1f, 0.1f},
                     {0.1f, 0.1f, 0.1f},
                     {-0.1f, 0.1f, 0.1f},
                     {-0.1f, -0.1f, -0.1f},
                     {0.1f, -0.1f, -0.1f},
                     {0.1f, 0.1f, -0.1f},
                     {-0.1f, 0.1f, -0.1f},
                     {0.0f, 0.0f, 0.0f}
    

    }; //problem of ambiguous 
    
coordinate Monster;


const int sprite[5][5] =   {
    { 0,0,0,0,1 },
    { 0,0,1,1,1 },
    { 1,1,1,1,1 },
    { 0,0,1,1,1 },
    { 0,0,0,0,1 },
};


coordinate camera;
coordinate camera_absolute={0,0,0};
coordinate relative_distance;
//Pin assignment format:  lcd(IO, Ser_TX, Ser_RX, MOSI, SCLK, PWM)  

    float y_pos = 24;
    float x_pos = 42;
        //convert 3D to 2D
    double angleX = 0.8, angleY = 0, angleZ = 0; // change the angle
    double scale = 2.0f;


        vec3d rotatepoint = {1, 1, 1};
int main(void)
{
    float cntl_val = 0;
    buttonA.rise(&buttonA_isr); 
     buttonA.mode(PullNone);
    init();

    float initialpoint = block[0][0];
    matrix tree_part1 = {{-0.25f, -0.25f, 0.25f}, //8 cube vertices
                     {0.25f, -0.25f, 0.25f},
                     {0.25f, 0.25f, 0.25f},
                     {-0.25f, 0.25f, 0.25f},
                     {-0.25f, -0.25f, -0.25f},
                     {0.25f, -0.25f, -0.25f},
                     {0.25f, 0.25f, -0.25f},
                     {-0.25f, 0.25f, -0.25f},
                     {0.0f, 0.3f, 0.0f}
    

    };
    matrix tree_part2 = {{-0.25f, -0.15f, 0.25f}, //8 cube vertices
                     {0.5f, -0.15f, 0.25f},
                     {0.5f, 0.15f, 0.25f},
                     {-0.25f, 0.15f, 0.25f},
                     {-0.25f, -0.15f, -0.25f},
                     {0.5f, -0.15f, -0.25f},
                     {0.5f, 0.15f, -0.25f},
                     {-0.25f, 0.15f, -0.25f},
                     {0.0f, 0.0f, 0.0f}
    

    };

        //1.先初始化位置，初始化图像，记录原来坐标(也许不需要)
      //  for (int i = 0; i < block.size()-1; i++)
    //{
     //   block[i][0] += block[8][0];
      //  block[i][1] += block[8][2];
       // block[i][2] += block[8][1];
    //}
    while (1)
    {
        lcd.clear();
        menu();
        
        if (joystick.get_direction()!=0) {
            //move joystick
            if (joystick.get_direction()==W) {
                direction = UP;
            }else if (joystick.get_direction()==E) {
            direction = DOWN;
            }else {
            continue;
            }
        state = gamemenu[state].next_state[direction];
        }
                
        lcd.drawSprite(gamemenu[state].x_menu, gamemenu[state].y_menu, 5, 5, (int *)sprite);    
        lcd.refresh();
        if (joystick.Button_press()) {
        switch (state) {
        case 0:
        map[0].x= 2;
        map[0].y = 2;
        map[1].x = 2;
        map[1].y = 4;
        map[2].x = 2;
        map[2].y = 8;
        map->num = 3;
        thread_segment.start(segment_module);
        *life = 9;
        game(block);
        break;
        case 1:
        thread_segment.start(segment_module);
        game(block);
        break;
        case 2:
        menu_setting();
        break;
        }
        }
      //  else {
   // while (1) {
       // lcd.clear();


      //  block = run(block);
        }

        //2.根据原来坐标，根据camera在joystick的变化，变换矩阵
//MOVE THE CAMERA

}
void segment_module()
{
    segment.init();
    while (1) {
    segment.show_remaining_live(*life);
    }
}

void init()
{
    joystick.init();
    lcd.init(LPH7366_1);        //initialise for LPH7366-1 LCD (Options are LPH7366_1 and LPH7366_6)
    mma8452.init();  // 100 Hz update rate, ±4g scale
}
void game(matrix block)
{
    Acceleration acceleration;  // Accleration structure declared in MMA8452 class
    coordinate load_value;
    matrix temp_Monster_head;
    matrix temp_Monster_body;
    matrix *monster_head1 = &temp_Monster_head;
    matrix *monster_body1 = &temp_Monster_body;
    camera_absolute.x = 0;
    camera_absolute.y = 0;
    Monster.x = 1;
    Monster.y= -1;
    float height = 0;
    matrix *two_leg = new matrix[2];
matrix *two_legs = new matrix[2];
    int num_block = map->num;
    matrix *multiblock = new matrix[30];
    for (int i = 0; i<map->num; i++) {
         multiblock[i]=matMove(block,map[i].x,map[i].y,map[i].z);
    }
        two_leg[0] = matMove(  monster_leg, 0, 0, 0);
    two_leg[1] = matMove(  monster_leg, 0, 0, 0);
    *monster_head1 = matMove(monster_head, 0, 0, 0);
    *monster_body1 = matMove(monster_body, 0, 0, 0);

    two_leg[0] = matMove(  monster_leg, 0.2, 0.3, 0);
    two_leg[1] = matMove(  monster_leg, 0, 0.3, 0);
    *monster_head1 = matMove(*monster_head1, 0.11, 0.1, 0);
    *monster_body1 = matMove(*monster_body1, 0.11, -0.2, 0);
    two_leg[0] = matMove(two_leg[0], Monster.x, Monster.y, 0);
    two_leg[1] = matMove(two_leg[1],Monster.x, Monster.y, 0);
    *monster_head1 = matMove(*monster_head1, Monster.x, Monster.y, 0);
    *monster_body1 = matMove(*monster_body1,Monster.x, Monster.y, 0);
    int avoid_repition = 0;
   while (1) {
       lcd.clear();

           if(*life ==0)
    {
        music.over_music();

        lcd.printString("   Gameover    ", 0, 1);
        lcd.refresh();
        ThisThread::sleep_for(5000ms);
			break;
    }
 
        acceleration = mma8452.readValues();   // read current values and print over serial port
        angleX=acceleration.x+0.8;//change the angle by move the 
        angleY=acceleration.y;
    height = pot1.read()-height;
            avoid_repition+=1;
    if (joystick.Button_press()&&(avoid_repition%4==3)) {
        int repeat = 0;

        num_block+=1;
       load_value = new_object_position(camera_absolute);
       for (int i = 0; i<map->num; i++) {
        if(abs(map[i].x-camera_absolute.x)<0.1&&abs(map[i].y-camera_absolute.y)<0.1)
        {
            repeat += 1;
        }

       }
           multiblock[num_block-1] = matMove(block,load_value.x,load_value.y,repeat*0.4);

       
       map[map->num].x = camera_absolute.x;
       map[map->num].y = camera_absolute.y;
       map[map->num].z = repeat*0.4;
      map->num+=1;
    }
    
      run(multiblock,two_leg, two_legs, height,num_block,life,monster_head1,monster_body1);
              if (g_buttonA_flag) {
            g_buttonA_flag = 0;  // if it has, clear the flag
			break;
        }

    }
}
void run(matrix *multiblock,matrix *two_leg,matrix *two_legs,float height,int num_block,int *life,matrix *monster_head1, matrix *monster_body1)
{

return_monster monster_value;
    *num_loop_pointer+=1;
        double distance = 2;
    if (joystick.get_direction()!=0) {
    

        if(joystick.get_direction() == S){
        camera.x = 0.1;
        camera.y = 0;
        camera_absolute.x -= 0.1;
        }
        else if (joystick.get_direction() == N) {
        camera.x = -0.1;
        camera.y = 0;
        camera_absolute.x +=0.1;
        }
        else if (joystick.get_direction() == W) {
        camera.x=0;
        camera.y = 0.1;
        camera_absolute.y += 0.1;
        }
        else if (joystick.get_direction() == E) {
        camera.x=0;
        camera.y = -0.1;
        camera_absolute.y -= 0.1;

        }
        else if (joystick.get_direction() == SW) {
        camera.x = 0.1;
        camera.y = 0.1;
        camera_absolute.x -= 0.1;
        camera_absolute.y += 0.1;
        }
        else if (joystick.get_direction() == SE) {
        camera.x = 0.1;
        camera.y = -0.1;
        camera_absolute.x -= 0.1;
        camera_absolute.y -= 0.1;
        }
        else if (joystick.get_direction() == NW) {
        camera.x = -0.1;
        camera.y = 0.1;
        camera_absolute.x += 0.1;
        camera_absolute.y += 0.1;
        }
        else if (joystick.get_direction() == NE) {
        camera.x = -0.1;
        camera.y = -0.1;
        camera_absolute.x += 0.1;
        camera_absolute.y -= 0.1;
        }
        //calculate relative position
        block[8][0] = camera_absolute.x;
        block[8][1] = camera_absolute.y;
        


        for (int i = 0;i<num_block;i++)
        {
            multiblock[i] = matMove(multiblock[i],camera.x,camera.y,camera.z);
        }
        //printf("%f %f %f\n",camera.x,camera.y,camera.z);
            two_leg[0] = matMove(two_leg[0], camera.x, camera.y, 0);
            two_leg[1] = matMove(two_leg[1],camera.x, camera.y, 0);
            *monster_head1 = matMove(*monster_head1, camera.x, camera.y, 0);
            *monster_body1 = matMove(*monster_body1,camera.x,camera.y, 0);

    }
    monster_value= monster_move(map,two_leg, camera_absolute,Monster,monster_head1,monster_body1);
    Monster.x = monster_value.x;
    Monster.y = monster_value.y;
    if(  monster_value.hurt &&*pointer_mode&&*num_loop_pointer>=5)
    {
        music.hurt_music();
        *num_loop_pointer =0;
        *life -=1;
    };

    // draw the whole part of the monster 


    two_legs[0] = calpoints(two_leg[0] ,rotatepoint,angleX, angleY , angleZ+0.3,   scale ,
            distance);
    two_legs[1] =  calpoints(two_leg[1] ,rotatepoint,angleX , angleY , angleZ+0.3 ,   scale ,
            distance);
    matrix monster_head1s = calpoints(*monster_head1,rotatepoint,angleX , angleY , angleZ+0.3,   scale ,
            distance);
    matrix monster_body1s = calpoints(*monster_body1, rotatepoint, angleX, angleY , angleZ+0.3,   scale,
            distance);
            if(*pointer_mode)
            {
            draw(two_legs[0]);
            draw(two_legs[1]);
            draw(monster_head1s);
            draw(monster_body1s);
            }

matrix blocks;
//matrix monster1s;
        for (int i = 0;i<num_block;i++)
        {
            blocks = calpoints(multiblock[i],rotatepoint,angleX , angleY , angleZ ,   scale ,
            distance);
    draw(blocks);
        }

    lcd.refresh();
        height = pot1.read();
    ThisThread::sleep_for(100ms);
    height = pot1.read()-height;
    for (int i = 0;i<num_block;i++)
        {
            multiblock[i] = matMove(multiblock[i],0,0,height);
        }
    two_leg[0] = matMove(two_leg[0], 0, 0, height);
    two_leg[1] = matMove(two_leg[1],0, 0, height);
    *monster_head1 = matMove(*monster_head1, 0, 0, height);
    *monster_body1 = matMove(*monster_body1,0, 0, height);
}

void menu()
{

    lcd.printString("   Mini Craft      ", 0, 0);
    thread_sleep_for(500);
    lcd.printString(" New Game", 0, 2);
    lcd.printString(" load Game", 0, 3);
    lcd.printString(" Setting", 0, 4);
    thread_sleep_for(500);
    

}

void setting_content(float set_contrast,float set_bright)
{
            lcd.clear();
    char buffer_contrast[26];
    char buffer_light[26];
        sprintf(buffer_contrast,"contrast: %3f ",set_contrast);
    lcd.printString(buffer_contrast,0,2);

    sprintf(buffer_light,"   light: %3f ",set_bright);
    lcd.printString("   setting    ", 0, 0);
    thread_sleep_for(500);
    lcd.printString(buffer_light, 0, 3);
    if(*pointer_mode==0)
    {
    lcd.printString("   Peace", 0, 4);
    }
    else
    {
    lcd.printString("  Monster", 0, 4);   
    }
  
    lcd.refresh();
        lcd.setContrast(set_contrast);      //set contrast to 55%
    lcd.setBrightness(set_bright);     
}
void menu_setting()
{
    while (1) {

    float set_contrast = 0.55;
    float set_bright = 0.5;
setting_content(set_contrast, set_bright);
    //control part
    
        if (joystick.get_direction()!=0) {
            //move joystick
            if (joystick.get_direction()==W) {
                direction = UP;
            }else if (joystick.get_direction()==E) {
            direction = DOWN;
            }else {
            continue;
            }
        state = gamemenu[state].next_state[direction];
        }
                    lcd.drawSprite(gamemenu[state].x_menu, gamemenu[state].y_menu, 5, 5, (int *)sprite);  
        lcd.refresh();
        if (joystick.Button_press()) {
        switch (state) {
        case 0:
        while (1) {
            
            setting_content(set_contrast, set_bright);
            lcd.printString("    modifying    ", 0, 1);
            lcd.refresh();
            if (joystick.get_direction()!=0) {
            //move joystick
            if (joystick.get_direction()==W) {
                set_contrast+=0.05;
            }else if (joystick.get_direction()==E) {
            set_contrast-=0.05;
            }else {
            continue;
            }
        }
                    if (g_buttonA_flag) {
            g_buttonA_flag = 0;  // if it has, clear the flag
			break;
        }
        }
        break;
        case 1:
        while (1) {

setting_content(set_contrast, set_bright);
            lcd.printString("   modifying    ", 0, 1);
            lcd.refresh();
        if (joystick.get_direction()!=0) {
            //move joystick
            if (joystick.get_direction()==W) {
                set_bright+=0.05;
            }else if (joystick.get_direction()==E) {
            set_bright-=0.05;
            }else {
            continue;
            }
        }
                    if (g_buttonA_flag) {
            g_buttonA_flag = 0;  // if it has, clear the flag
			break;
        }
        }
        break;
        case 2:
        while (1) {
 
setting_content(set_contrast, set_bright);
           lcd.printString("   modifying    ", 0, 1);
           lcd.refresh();
                if (joystick.get_direction()!=0) {
            //move joystick
            if (joystick.get_direction()==W) {
                *pointer_mode = 1;
            }else if (joystick.get_direction()==E) {
            *pointer_mode = 0;
            }else {
            continue;
            }

                }
                            if (g_buttonA_flag) {
            g_buttonA_flag = 0;  // if it has, clear the flag
			break;
        }
        }
        break;
        }
        }
            if (g_buttonA_flag) {
            g_buttonA_flag = 0;  // if it has, clear the flag
			break;
        }
    thread_sleep_for(500);
    }


}
void draw(matrix blocks)
{
    //draw or not 
    int num_neg = 0;
    for(int i = 0;i<8;i++)
    {
        if(blocks[i][0]<0)
        {
            num_neg++;
        }
        if(blocks[i][1]<0)
        {
            num_neg++;
        }
    }
    if (num_neg<4) {
                for (int i = 0; i < 4; i++) //draw tree1 edges
        {
            lcd.drawLine(blocks[i][0], blocks[i][1], blocks[(i + 1) % 4][0], blocks[(i + 1) % 4][1],1);
            lcd.drawLine(blocks[i + 4][0], blocks[i + 4][1], blocks[((i + 1) % 4) + 4][0], blocks[((i + 1) % 4) + 4][1],1);
            lcd.drawLine(blocks[i][0], blocks[i][1], blocks[i + 4][0], blocks[i + 4][1],1);
            
        }
    }

}





return_monster monster_move(Map *map,matrix *two_leg, coordinate player,coordinate Monster,matrix *monster_head1, matrix *monster_body1)
{
    bool hurt;
    return_monster monster_data;
    coordinate temp_Monster;
    coordinate temp_move;
    temp_move.x =0;
    temp_move.y =0;
        printf("x:%f,y:%f\n",Monster.x,Monster.y);
    printf("playerx:%f,playery:%f\n",player.x,player.y);
    
    if(Monster.x - player.x < -0.3)
    {
        temp_Monster.x = Monster.x+monster_move_speed;
        temp_move.x = monster_move_speed;
    }
    else if(Monster.x - player.x > 0.3){
        temp_Monster.x =Monster.x-monster_move_speed;
        temp_move.x =-monster_move_speed;
    }
    else {
        temp_Monster.x =Monster.x;
        temp_move.x =0;
    }
    if (Monster.y - player.y<-0.3) {
        temp_Monster.y =Monster.y+monster_move_speed;
        temp_move.y =monster_move_speed;
    }
    else if(Monster.y - player.y > 0.3){
        temp_Monster.y =Monster.y-monster_move_speed;
        temp_move.y =-monster_move_speed;
    }
    else {
        temp_Monster.y =Monster.y;
        temp_move.y =0;
    }
    int ran_move = rand()%50;
    if(ran_move>30)
    {
        temp_Monster.x =Monster.x-monster_move_speed;
        temp_move.x =-monster_move_speed;
    }
    while (!collisition_detect(map,Monster)) {
        temp_Monster = Monster;
        int move_direction = rand()%100 ;
        
        if(move_direction > 75)
        {
            temp_Monster.y =Monster.y+monster_move_speed;
            temp_move.y =monster_move_speed;
        }
        else if (move_direction >50 && move_direction<75) {
        temp_Monster.y =Monster.y-monster_move_speed;
        temp_move.y =-monster_move_speed;
        }
        else if (move_direction >25 && move_direction<50) {
        temp_Monster.y =Monster.x+monster_move_speed;
        temp_move.x =monster_move_speed;
        }
        else if (move_direction >0 && move_direction<25) {
        temp_Monster.y =Monster.x-monster_move_speed;
        temp_move.x =-monster_move_speed;
        }
    }
    printf("tempx:%f,tempy:%f\n",temp_move.x,temp_move.y);
    Monster = temp_Monster;
    two_leg[0] = matMove(two_leg[0], temp_move.x , 1.5*temp_move.y , 0);
    two_leg[1] = matMove(two_leg[1],temp_move.x , 1.5*temp_move.y , 0);
    *monster_head1 = matMove(*monster_head1, temp_move.x , 1.5*temp_move.y , 0);
    *monster_body1 = matMove(*monster_body1,temp_move.x , 1.5*temp_move.y , 0);

    //printf("x:%f,y:%f\n",temp_move.x,temp_move.y);
    double target_distance = sqrt((Monster.x-player.x)*(Monster.x-player.x)+(Monster.y-player.y)*(Monster.y-player.y));
    //
    //printf("x:%f\n",target_distance);
    if (target_distance<0.3) {
    hurt = true;
    }
    else {
    hurt = false;
    }
    printf("after x:%f,y:%f\n",Monster.x,Monster.y);
        monster_data.x = Monster.x;
    monster_data.y = Monster.y;
    monster_data.hurt = hurt;
    return monster_data;
}
int collisition_detect(Map *map,coordinate object)
{
    int which_wrong=0;
    for(int i;i<=map->num;i++)
    {
        if((map[i].x==object.x)&&(map[i].y!=object.y))
        {
            which_wrong = 1;
        }
        else if ((map[i].x!=object.x)&&(map[i].y==object.y)) {
            which_wrong = 2;
        }
        else if ((map[i].x==object.x)&&(map[i].y==object.y)) {
            which_wrong=0;
        }
        else {
            which_wrong = 3;
        }
    }
    return which_wrong;
}
void buttonA_isr(){
    g_buttonA_flag = 1;   // set flag in ISR
}
