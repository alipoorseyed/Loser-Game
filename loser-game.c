#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void first_menu_function(char aryy[])
{
    printf("welcome To Losergame !\n");
    printf("1-Login\n2-Signup\n3-Exit\n");
    printf("which one is your choice (Enter) : ");
    scanf("%s",aryy);
}
void second_menu_function(char arry[])
{
    printf("Welcome To Second Menu !\n");
    printf("1-Start game\n2-Show leaderboard\n3-New word\n4-Exit\n");
    printf("If you want to go to the next sections, just enter the first part of the words !\n");
    printf("which one is your choice (Enter) : ");
    scanf("%s",arry);
}
int main()
{
    srand(time(0));
    char write_aryy_username[100]={'\0'};
    char write_aryy_password[100]={'\0'};
    char read_aryy_username[100]={'\0'};
    char read_aryy_password[100]={'\0'};
    char read_aryy_word[100]={'\0'};
    char read_aryy_word_same[100]={'\0'};
    char write_aryy_word[100]={'\0'};
    char check_word[100]={'$'};
    char read_aryy_leaderboard[100]={'\0'};
    char empty[100]={'\0'};
    char empty_show[100]={'\0'};
    char show[100]={'\0'};
    char word[100]={'\0'};
    char menu1[100]={'\0'};
    char menu2[100]={'\0'};
    char menu3[100]={'\0'};
    char menu4[100]={'\0'};
    char menu_in_game[100]={'\0'};
    char menu_in_game_final[100]={'\0'};
    char menu5[100]={'\0'};
    int counter=0,counter2=0,counter3=0,counter4=0,counter5=0,counter6=0,counter7=0,counter_leaderboard=0,score=0,j=0,scoer_final=0,counter_pointer=0;
    int counter_in_game=0,counter_for_win=0,counter_for_win_final=0,counter_check_word=0,i=0,k=0,i_word=0,rand_word=0,pointer_location=0,score_show=0;
    FILE* fptr_username;
    FILE* fptr_password;
    FILE* fptr_word;
    FILE* fptr_leaderboard;
    FILE* fptr_show;
    do
    {
        first_menu_function(menu1);
        system("cls");
        if(strcmp(menu1,"Login")==0 || strcmp(menu1,"login")==0 || strcmp(menu1,"LOGIN")==0 || strcmp(menu1,"1")==0)
        {
            do{
                memset(menu4,'\0',100);
            printf("Enter your username : ");
            scanf("%s",write_aryy_username);
            printf("Enter your password : ");
            scanf("%s",write_aryy_password);
            fptr_username=fopen("losergame_username.txt","r");
            i=0;
            counter6=0;
                    while(fgets(read_aryy_username,100,fptr_username))
                    {
                        i=i+1;
                        fscanf(fptr_username,"%s",read_aryy_username);
                        if(strcmp(write_aryy_username,read_aryy_username)==0)
                        {
                            counter6=counter6+1;
                            break;
                        }
                    }
                    fclose(fptr_username);
                    fptr_password=fopen("losergame_password.txt","r");
                    for(int j=1 ; j<=i ; j++)
                    {
                        fscanf(fptr_password,"%s",read_aryy_password);
                        if(j==i)
                        {
                            if(strcmp(write_aryy_password,read_aryy_password)==0)
                            {
                                counter6=counter6+1;
                            }
                        }
                    }
                    fclose(fptr_password);
                    if(counter6==2)
                    {
                        do{
                            memset(menu_in_game,'\0',100);
                        system("cls");
                        second_menu_function(menu_in_game);
                        system("cls");
                        if(strcmp(menu_in_game,"start")==0 || strcmp(menu_in_game,"Start")==0 || strcmp(menu_in_game,"START")==0 || strcmp(menu_in_game,"1")==0)
                        {
                            i_word=0;
                            fptr_word=fopen("losergame_word.txt","r");
                            while(fgets(read_aryy_word,100,fptr_word))
                            {
                                fscanf(fptr_word,"%s",read_aryy_word);
                                i_word=i_word+1;
                            }
                            fclose(fptr_word);
                            if(i_word==0)
                            {
                                printf("The game has no words !\n");
                                printf("if you want to play , you must go to (new word) and add a word !\n");
                                printf("if you want to return enter (yes) or if not enter (no) !\n");
                                scanf("%s",menu_in_game);
                                system("cls");
                            }
                            else{
                                fptr_word=fopen("losergame_word.txt","r");
                                rand_word=(rand()%i_word)+1;
                                for(int i=1 ; i<=rand_word ; i++)
                                {
                                    fscanf(fptr_word,"%s",read_aryy_word);
                                }
                                fclose(fptr_word);
                                if(strlen(read_aryy_word)<=8)
                                {
                                    do{
                                        memset(menu_in_game_final,'\0',100);
                                        k=0;
                                        memset(word,'\0',100);
                                        memset(check_word,'\0',100);
                                        memset(read_aryy_word_same,'\0',100);
                                        counter_in_game=0;
                                        counter_for_win_final=0;
                                        counter_pointer=0;
                                        for(int i=0 ; read_aryy_word[i] ; i++)
                                        {
                                             read_aryy_word_same[i]='-';
                                        }
                                    while(1)
                                    {
                                        system("cls");
                                         counter_for_win=0;
                                        for(int i=0 ; read_aryy_word[i] ; i++)
                                        {
                                            if(word[0]==read_aryy_word[i])
                                            {
                                                read_aryy_word_same[i]=word[0];
                                                counter_for_win=counter_for_win+1;
                                            }
                                        }
                                          if(counter_for_win>0)
                                          {
                                            for(int i=1 ; i<=counter_for_win ; i++)
                                            {
                                                counter_for_win_final=counter_for_win_final+1;
                                            }
                                          }
                                          else{
                                            counter_in_game=counter_in_game+1;
                                          }
                                        printf("%s\n\n",read_aryy_word_same);
                                        printf("__________________________________");
                                        printf("\n\n");
                                        if(counter_for_win_final==strlen(read_aryy_word))
                                        {
                                            system("cls");
                                            printf("%s\n",read_aryy_word);
                                            counter_pointer=counter_pointer+1;
                                            printf("you win the game !\n");
                                            printf("if you want to return to back menu enter (yes) or if not enter (no) !\n");
                                            scanf("%s",menu_in_game);
                                            system("cls");
                                            break;
                                        }
                                        if(counter_in_game==1)
                                        {
                                            printf("->");
                                        }
                                        else if(counter_in_game==2)
                                        {
                                            printf("->L");
                                        }
                                        else if(counter_in_game==3)
                                        {
                                            printf("->LO");
                                        }
                                        else if(counter_in_game==4)
                                        {
                                            printf("->LOS");
                                        }
                                        else if(counter_in_game==5)
                                        {
                                            printf("->LOSE");
                                        }
                                        else if(counter_in_game==6)
                                        {
                                            printf("->LOSER");
                                        }
                                        else if(counter_in_game==7)
                                        {
                                            system("cls");
                                            printf("You lose the game !\n");
                                            printf("if you want to try again with this word enter (yes) or if not enter (no) !\n");
                                            scanf("%s",menu_in_game_final);
                                            strcpy(menu_in_game,"yes");
                                            system("cls");
                                            break;
                                        }
                                        printf("\n\n");
                                        printf("__________________________________");
                                        printf("\n\n");
                                        printf("enter a word : ");
                                          scanf("%s",word);
                                          do{
                                            counter_check_word=0;
                                          for(int i=0 ; check_word[i] ; i++)
                                          {
                                            if(word[0]==check_word[i])
                                            {
                                                printf("This word has already been entered !\n");
                                                printf("List of entered words :\n");
                                                for(int j=0 ; check_word[j] ; j++)
                                                {
                                                    printf("%c\n",check_word[j]);
                                                }
                                                printf("enter another word : ");
                                                scanf("%s",word);
                                                system("cls");
                                                counter_check_word=counter_check_word+1;
                                                break;
                                            }
                                          }
                                             }while(counter_check_word!=0);
                                            check_word[k]=word[0];
                                            k=k+1;
                                            system("cls");
                                    }
                                      } while(strcmp(menu_in_game_final,"yes")==0 || strcmp(menu_in_game_final,"Yes")==0 || strcmp(menu_in_game_final,"YES")==0);
                                }
                                else{
                                    do{
                                        memset(menu_in_game_final,'\0',100);
                                        k=0;
                                        memset(word,'\0',100);
                                        memset(check_word,'\0',100);
                                        memset(read_aryy_word_same,'\0',100);
                                        counter_in_game=0;
                                        counter_pointer=0;
                                        counter_for_win_final=0;
                                        for(int i=0 ; read_aryy_word[i] ; i++)
                                        {
                                             read_aryy_word_same[i]='-';
                                        }
                                    while(1)
                                    {
                                        system("cls");
                                         counter_for_win=0;
                                        for(int i=0 ; read_aryy_word[i] ; i++)
                                        {
                                            if(word[0]==read_aryy_word[i])
                                            {
                                                read_aryy_word_same[i]=word[0];
                                                counter_for_win=counter_for_win+1;
                                            }
                                        }
                                          if(counter_for_win>0)
                                          {
                                            for(int i=1 ; i<=counter_for_win ; i++)
                                            {
                                                counter_for_win_final=counter_for_win_final+1;
                                            }
                                          }
                                          else{
                                            counter_in_game=counter_in_game+1;
                                          }
                                        printf("%s\n\n",read_aryy_word_same);
                                        printf("__________________________________");
                                        printf("\n\n");
                                        if(counter_for_win_final==strlen(read_aryy_word))
                                        {
                                            system("cls");
                                            printf("you win the game !\n");
                                            printf("if you want to return to back menu enter (yes) or if not enter (no) !\n");
                                            counter_pointer=counter_pointer+1;
                                            scanf("%s",menu_in_game);
                                            system("cls");
                                            break;
                                        }
                                        if(counter_in_game==1 || counter_in_game==2)
                                        {
                                            printf("->");
                                        }
                                        else if(counter_in_game==3 || counter_in_game==4)
                                        {
                                            printf("->L");
                                        }
                                        else if(counter_in_game==5 || counter_in_game==6)
                                        {
                                            printf("->LO");
                                        }
                                        else if(counter_in_game==7 || counter_in_game==8)
                                        {
                                            printf("->LOS");
                                        }
                                        else if(counter_in_game==9 || counter_in_game==10)
                                        {
                                            printf("->LOSE");
                                        }
                                        else if(counter_in_game==11 || counter_in_game==12)
                                        {
                                            printf("->LOSER");
                                        }
                                        else if(counter_in_game==13)
                                        {
                                            system("cls");
                                            printf("You lose the game !\n");
                                            printf("if you want to try again with this word enter (yes) or if not enter (no) !\n");
                                            strcpy(menu_in_game,"yes");
                                            scanf("%s",menu_in_game_final);
                                            system("cls");
                                            break;
                                        }
                                        printf("\n\n");
                                        printf("__________________________________");
                                        printf("\n\n");
                                        printf("enter a word : ");
                                          scanf("%s",word);
                                          do{
                                            counter_check_word=0;
                                          for(int i=0 ; check_word[i] ; i++)
                                          {
                                            if(word[0]==check_word[i])
                                            {
                                                printf("This word has already been entered !\n");
                                                printf("List of entered words :\n");
                                                for(int j=0 ; check_word[j] ; j++)
                                                {
                                                    printf("%c\n",check_word[j]);
                                                }
                                                printf("enter another word : ");
                                                scanf("%s",word);
                                                system("cls");
                                                counter_check_word=counter_check_word+1;
                                                break;
                                            }
                                          }
                                             }while(counter_check_word!=0);
                                            check_word[k]=word[0];
                                            k=k+1;
                                            system("cls");
                                    }
                                      } while(strcmp(menu_in_game_final,"yes")==0 || strcmp(menu_in_game_final,"Yes")==0 || strcmp(menu_in_game_final,"YES")==0);
                                }
                                if(counter_pointer==1)
                                {
                                            counter_leaderboard=0;
                                            j=0;
                                            scoer_final=0;
                                            memset(read_aryy_leaderboard,'\0',100);
                                            memset(empty,'\0',100);
                                            score=strlen(read_aryy_word);
                                            fptr_leaderboard=fopen("losergame_leaderboard.txt","r");
                                            while(fgets(read_aryy_leaderboard,100,fptr_leaderboard))
                                            {
                                                fscanf(fptr_leaderboard,"%s%s%d",read_aryy_leaderboard,empty,&scoer_final);
                                                j=j+1;
                                                if(strcmp(write_aryy_username,read_aryy_leaderboard)==0)
                                                {
                                                    counter_leaderboard=counter_leaderboard+1;
                                                    break;
                                                }
                                            }
                                            fclose(fptr_leaderboard);
                                            if(counter_leaderboard==0)
                                            {
                                                fptr_leaderboard=fopen("losergame_leaderboard.txt","a");
                                                fprintf(fptr_leaderboard,"\n%s --------- %d",write_aryy_username,score);
                                                fclose(fptr_leaderboard);
                                            }
                                            else{
                                                fptr_leaderboard=fopen("losergame_leaderboard.txt","r");
                                                for(int i=1 ; i<=j ; i++)
                                                {
                                                    fscanf(fptr_leaderboard,"%s%s%d",read_aryy_leaderboard,empty,&scoer_final);
                                                    if(i==j-1)
                                                    {
                                                        pointer_location=ftell(fptr_leaderboard);
                                                    }
                                                }
                                                fclose(fptr_leaderboard);
                                                scoer_final=scoer_final+score;
                                                fptr_leaderboard=fopen("losergame_leaderboard.txt","r+");
                                                pointer_location=pointer_location+strlen(write_aryy_username)+13;
                                                fseek(fptr_leaderboard,pointer_location,0);
                                                fprintf(fptr_leaderboard,"%d",scoer_final);
                                                fclose(fptr_leaderboard);
                                            }
                                }
                                else if(counter_pointer==0)
                                {
                                            counter_leaderboard=0;
                                            j=0;
                                            scoer_final=0;
                                            memset(read_aryy_leaderboard,'\0',100);
                                            memset(empty,'\0',100);
                                            score=strlen(read_aryy_word);
                                            fptr_leaderboard=fopen("losergame_leaderboard.txt","r");
                                            while(fgets(read_aryy_leaderboard,100,fptr_leaderboard))
                                            {
                                                fscanf(fptr_leaderboard,"%s%s%d",read_aryy_leaderboard,empty,&scoer_final);
                                                j=j+1;
                                                if(strcmp(write_aryy_username,read_aryy_leaderboard)==0)
                                                {
                                                    counter_leaderboard=counter_leaderboard+1;
                                                    break;
                                                }
                                            }
                                            fclose(fptr_leaderboard);
                                            if(counter_leaderboard==0)
                                            {
                                                fptr_leaderboard=fopen("losergame_leaderboard.txt","a");
                                                fprintf(fptr_leaderboard,"\n%s --------- %d",write_aryy_username,0);
                                                fclose(fptr_leaderboard);
                                            }
                                }
                            }
                        }
                        else if(strcmp(menu_in_game,"show")==0 || strcmp(menu_in_game,"Show")==0 || strcmp(menu_in_game,"SHOW")==0 || strcmp(menu_in_game,"2")==0)
                        {
                                system("cls");
                                fptr_show=fopen("losergame_leaderboard.txt","r");
                                printf("leaderboard is : \n\n");
                                while(fgets(show,100,fptr_show))
                                {
                                    fscanf(fptr_show,"%s%s%d",show,empty_show,&score_show);
                                    printf("%s %s %d\n",show,empty_show,score_show);
                                }
                                fclose(fptr_show);
                                printf("\nif you want ruturn to back menu enter (yes) or if not enter (no) !\n");
                                scanf("%s",menu_in_game);
                                system("cls");
                        }
                        else if(strcmp(menu_in_game,"new")==0 || strcmp(menu_in_game,"New")==0 || strcmp(menu_in_game,"NEW")==0 || strcmp(menu_in_game,"3")==0)
                        {
                                do{
                                    memset(menu5,'\0',100);
                                    counter7=0;
                                printf("Enter your new word : ");
                                scanf("%s",write_aryy_word);
                                system("cls");
                                fptr_word=fopen("losergame_word.txt","r");
                                while(fgets(read_aryy_word,100,fptr_word))
                                {
                                    fscanf(fptr_word,"%s",read_aryy_word);
                                    if(strcmp(write_aryy_word,read_aryy_word)==0)
                                    {
                                         printf("This word exists !\n");
                                         printf("if you want to try again enter (yes) or if not enter (no) !\n");
                                         counter7=counter7+1;
                                         scanf("%s",menu5);
                                         system("cls");
                                         break;
                                    }
                                }
                                strcpy(menu_in_game,"yes");
                                fclose(fptr_word);
                                if(counter7==0)
                                {
                                    fptr_word=fopen("losergame_word.txt","a");
                                    fprintf(fptr_word,"\n%s",write_aryy_word);
                                    fclose(fptr_word);
                                    printf("Your word has been successfully registered !\n");
                                    printf("if you want to play the game , you must return to menu and select start !\n");
                                    printf("if you want to return enter (yes) or if not enter (no) !\n");
                                    scanf("%s",menu_in_game);
                                    system("cls");
                                }
                            }while(strcmp(menu5,"yes")==0 || strcmp(menu5,"Yes")==0 || strcmp(menu5,"YES")==0);
                        }
                        else if(strcmp(menu_in_game,"exit")==0 || strcmp(menu_in_game,"Exit")==0 || strcmp(menu_in_game,"EXIT")==0 || strcmp(menu_in_game,"4")==0)
                        {
                                strcpy(menu_in_game,"no");
                        }
                          } while(strcmp(menu_in_game,"yes")==0 || strcmp(menu_in_game,"Yes")==0 || strcmp(menu_in_game,"YES")==0);
                    }
                    else{
                        system("cls");
                        printf("Your username or password is incorrect !\n");
                        printf("if you want to try again enter (yes) or if not enter (no) !\n");
                        scanf("%s",menu4);
                        system("cls");
                    }
                    strcpy(menu1,"yes");
            }while(strcmp(menu4,"yes")==0 || strcmp(menu4,"Yes")==0 || strcmp(menu4,"YES")==0);
        }
        else if(strcmp(menu1,"signup")==0 || strcmp(menu1,"Signup")==0 || strcmp(menu1,"SIGNUP")==0 || strcmp(menu1,"2")==0)
        {
            do{
                memset(menu2,'\0',100);
            printf("Username cannot contain spaces !\n");
            printf("Enter your username : ");
            scanf("%s",write_aryy_username);
            fptr_username=fopen("losergame_username.txt","r");
            counter=0;
                    while(fgets(read_aryy_username,100,fptr_username))
                    {
                        fscanf(fptr_username,"%s",read_aryy_username);
                        if(strcmp(write_aryy_username,read_aryy_username)==0)
                        {
                            counter=counter+1;
                            system("cls");
                            printf("This username exists !\n");
                            printf("if you want to try again enter (yes) or if not enter (no) !\n");
                            scanf("%s",menu2);
                            break;
                        }
                    }
                    fclose(fptr_username);
                    strcpy(menu1,"yes");
                    system("cls");
                }while(strcmp(menu2,"yes")==0 || strcmp(menu2,"Yes")==0 || strcmp(menu2,"YES")==0);
            if(counter==0)
            {
            do{
                memset(menu3,'\0',100);
                printf("Password must be at least 8 characters long and contain a-z / A-Z / *&$@... letters and number\n");
                printf("Enter your password : ");
                scanf("%s",write_aryy_password);
                if(strlen(write_aryy_password)>=8)
                {
                    counter2=0;
                    for(int i=0 ; write_aryy_password[i] ; i++)
                    {
                        for(int j=33 ; j<=47 ; j++)
                        {
                            if(write_aryy_password[i]==(char)j)
                            {
                                counter2=counter2+1;
                            }
                        }
                    }
                    for(int i=0 ; write_aryy_password[i] ; i++)
                    {
                        for(int j=58 ; j<=64 ; j++)
                        {
                            if(write_aryy_password[i]==(char)j)
                            {
                                counter2=counter2+1;
                            }
                        }
                    }
                    if(counter2>0)
                    {
                        counter3=0;
                        for(int i=0 ; write_aryy_password[i] ; i++)
                        {
                            for(int j=48 ; j<=57 ; j++)
                            {
                                if(write_aryy_password[i]==(char)j)
                                {
                                    counter3=counter3+1;
                                }
                            }
                        }
                        if(counter3>0)
                        {
                            counter4=0;
                            for(int i=0 ; write_aryy_password[i] ; i++)
                            {
                                for(int j=65 ; j<=90 ; j++)
                                {
                                    if(write_aryy_password[i]==(char)j)
                                    {
                                        counter4=counter4+1;
                                    }
                                }
                            }
                            if(counter4>0)
                            {
                                counter5=0;
                                for(int i=0 ; write_aryy_password[i] ; i++)
                                {
                                    for(int j=97 ; j<=122 ; j++)
                                    {
                                        if(write_aryy_password[i]==(char)j)
                                        {
                                            counter5=counter5+1;
                                        }
                                    }
                                }
                                if(counter5>0)
                                {
                                    system("cls");
                                    fptr_password=fopen("losergame_password.txt","a");
                                    fprintf(fptr_password,"\n%s",write_aryy_password);
                                    fclose(fptr_password);
                                    fptr_username=fopen("losergame_username.txt","a");
                                    fprintf(fptr_username,"\n%s",write_aryy_username);
                                    fclose(fptr_username);
                                    printf("Your username and password have been successfully registered !\n");
                                    printf("If you want to play the game, you have to login !\n");
                                    printf("if you want to return enter (yes) or if not enter (no) !\n");
                                    scanf("%s",menu1);
                                    system("cls");
                                }
                            }
                        }
                    }
                }
                if(counter2==0 || counter3==0 || counter4==0 || counter5==0)
                {
                    system("cls");
                    printf("The password does not match your criteria !\n");
                    printf("if you want to try again enter (yes) or if not enter (no) !\n");
                    scanf("%s",menu3);
                    system("cls");
                }
            }while(strcmp(menu3,"yes")==0 || strcmp(menu3,"Yes")==0 || strcmp(menu3,"YES")==0);
            
        }
        }
        else if(strcmp(menu1,"exit")==0 || strcmp(menu1,"Exit")==0 || strcmp(menu1,"EXIT")==0 || strcmp(menu1,"3")==0)
        {
            printf("the game is over !");
        }
        else
        {
            printf("error ......\n");
            printf("Your request cannot be recognized !\n");
            printf("if you want to return enter (yes) or if not enter (no) !\n");
            scanf("%s",menu1);
            system("cls");
        }
            } while(strcmp(menu1,"yes")==0 || strcmp(menu1,"Yes")==0 || strcmp(menu1,"YES")==0);
    return 0;
}