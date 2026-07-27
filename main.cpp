#include <fstream>
#include<cstdio>
#include<string>
#include<filesystem>
#include <iostream>
using namespace std;
void c2cpp_path(string &str);//replaces '\' with '/'

#define CH 7
#define MAXCH 2
#define N_OST 50
const int n_ost[CH]={40,47,38,40,40,N_OST,N_OST};//song count per chapter
std::string ostname[CH][N_OST]=
{{ "1_01 - ANOTHER HIM"
, "1_02 - Beginning"
, "1_03 - School"
, "1_04 - Susie"
, "1_05 - The Door"
, "1_06 - Cliffs"
, "1_07 - The Chase"
, "1_08 - The Legend"
, "1_09 - Lancer"
, "1_10 - Rude Buster"
, "1_11 - Empty Town"
, "1_12 - Weird Birds"
, "1_13 - Field of Hopes and Dreams"
, "1_14 - Fanfare"
, "1_15 - Lantern"
, "1_16 - I'm Very Bad"
, "1_17 - Checker Dance"
, "1_18 - Quiet Autumn"
, "1_19 - Scarlet Forest"
, "1_20 - Thrash Machine"
, "1_21 - Vs. Lancer"
, "1_22 - Basement"
, "1_23 - Imminent Death"
, "1_24 - Vs. Susie"
, "1_25 - Card Castle"
, "1_26 - Rouxls Kaard"
, "1_27 - April 2012"
, "1_28 - Hip Shop"
, "1_29 - Gallery"
, "1_30 - Chaos King"
, "1_31 - Darkness Falls"
, "1_32 - The Circus"
, "1_33 - THE WORLD REVOLVING"
, "1_34 - Friendship"
, "1_35 - THE HOLY"
, "!1_36 - Your Power"
, "1_37 - A Town Called Hometown"
, "1_38 - You Can Always Come Home"
, "1_39 - Don't Forget"
, "1_40 - Before the Story"
}
,{ "2_01 - Faint Glow"
, "2_02 - Girl Next Door"
, "2_03 - My Castle Town"
, "2_04 - Ohhhhohohoho!"
, "2_05 - Queen"
, "2_06 - A CYBER'S WORLD;"//normaly has ? instead of ; but files cant have this character, while alternatives exist, i would need to convert to wchar_t which is a pain for portabilityh and i really dont wanna put any more effort
, "2_07 - A Simple Diversion"
, "2_08 - Almost to the Guys!"
, "2_09 - Cool Beat"
, "2_10 - When I Get Mad I Dance Like This"
, "2_11 - Cyber Battle"
, "2_12 - When I Get Happy I Dance Like This"
, "2_13 - Sound Studio"
, "2_14 - Berdly"
, "2_15 - Smart Race"
, "2_16 - Faint Courage"
, "2_17 - WELCOME TO THE CITY"
, "2_18 - Mini Studio"
, "2_19 - Holiday Studio"
, "2_20 - Cool Mixtape"
, "2_21 - HEY EVERY !"
, "2_22 - Spamton"
, "2_23 - NOW'S YOUR CHANCE TO BE A"
, "2_24 - Elegant Entrance"
, "2_25 - Bluebird of Misfortune"
, "2_26 - Pandora Palace"
, "2_27 - KEYGEN"
, "2_28 - Acid Tunnel of Love"
, "2_29 - It's Pronounced 'Rules'"
, "2_30 - Lost Girl"
, "2_31 - Ferris Wheel"
, "2_32 - Attack of the Killer Queen"
, "2_33 - Giga Size"
, "2_34 - Powers Combined"
, "2_35 - Knock You Down !!"
, "2_36 - The Dark Truth"
, "2_37 - Digital Roots"
, "2_38 - Deal Gone Wrong"
, "2_39 - BIG SHOT"
, "2_40 - A Real Boy!"
, "2_41 - Dialtone"
, "2_42 - sans."
, "2_43 - Chill Jailbreak Alarm to Study and Relax to"
, "2_44 - You Can Always Come Home"//~is an identifier that this file is copy of another with the same name but difrent place in ost
, "2_45 - Until Next Time"
, "2_46 - Before the Story"
, "!2_47 - Berdly"//not in games filess
}//the rest of OST is here cause i originally wanted to make this for all 5 chapters but that comes with many complications that am too lazy to deal with
,{ "3_01 - Flashback"
, "!3_02 - Feature Presentation"
, "3_03 - And Now For Today's Sponsors...!"
, "3_04 - MIKE, the BOARD, please!"
, "3_05 - Sandy Board"
, "3_06 - Adventure Board"
, "!3_07 - Query;"//unused not even in game files
, "3_08 - Quiz!"
, "3_09 - Dig! Dig! To The Center of the Earth!"
, "3_10 - Pushing Buddies"
, "3_11 - Ruder Buster"
, "3_12 - Physical Challenge"
, "3_13 - Board Clear!"
, "3_14 - Welcome to the Green Room"
, "3_15 - Vapor Buster"
, "3_16 - Paradise, Paradise"
, "3_17 - Raft Ride"
, "3_18 - SOUTH OF THE BORDER!!"
, "3_19 - Sound Check"
, "3_20 - Raise Up Your Bat"
, "3_21 - KING OF ROLYPOLY"
, "!3_22 - Glowing Snow"//probably in audiogroup.dat in chapter3 folder
, "3_23 - Big City Board"
, "3_24 - Doom Board"
, "3_25 - Metaphysical Challenge"
, "3_26 - TV WORLD"
, "3_27 - It's TV Time!"
, "3_28 - Hall of Fame"
, "3_29 - Breath"
, "3_30 - Black Knife"
, "3_31 - Crickets"
, "3_32 - Dump"
, "3_33 - SWORD"
, "3_34 - NORTHERNLIGHT"
, "3_35 - GLACEIR"
, "3_36 - BIT ROOTS"
, "3_37 - ERAM"
, "3_38 - BURNING EYES"
}
,{ "4_01 - Old wooden rafters"
, "4_02 - Hymn"
, "4_03 - Another day in hometown"
, "4_04 - Friends"
, "4_05 - Castle Funk"
, "4_06 - Knock You Down!!(Rhythm)"
, "4_07 - Gingerbread House"
, "4_08 - The distance between two"
, "4_09 - C"
, "4_10 - ATRIUM"
, "4_11 - Dark Sanctuary"
, "4_12 - From Now On"
, "4_13 - Gyaa Ha ha!"
, "4_14 - Fireplace"
, "4_15 - A DARK ZONE"
, "4_16 - Mysterious Ringing"
, "4_17 - Ever Higher"
, "4_18 - Wise words"
, "4_19 - Piano that may not be played that well"
, "4_20 - Hammer of Justice"
, "4_21 - 12am"
, "4_22 - The Second Sanctuary"
, "!4_23 - Ripple"
, "4_24 - 13am"
, "4_25 - The Third Sanctuary"
, "4_26 - Dark Place"
, "4_27 - Heavy Footsteps"
, "4_28 - Crumbling Tower"
, "4_29 - SPAWN"
, "4_30 - GUARDIAN"
, "4_31 - Need a hand!;"
, "4_32 - The place where it rained"//audiogroup
, "4_33 - The Ol' Jitterbug"
, "4_34 - Neverending Night"
, "4_35 - The LEGEND...;"
, "4_36 - With Hope Crossed On Our Hearts"
, "4_37 - Volume Adjustment"
, "4_38 - Catswing"
, "4_39 - Air Waves"
, "4_40 - Concert for you"//audiogroupu
}
,{ "5_01 - Chapter 5 Logo"
, "5_02 - Inappropriate Recycling"
, "5_03 - Pirate Dojo"
, "5_04 - 4rd Sanctuary"
, "5_05 - Festival"
, "5_06 - Catfession...;"
, "5_07 - Bratfession...;"
, "5_08 - I guess I'm in love"
, "5_09 - Weirder Birds"
, "5_10 - Your Dad's Best Friend"
, "!5_11 - Garden of Hopes and Dreams"//editing maybe
, "5_12 - Rakuichi Buster"
, "5_13 - The Diner Song of Best Friends"
, "5_14 - Ride the Board"
, "5_15 - Quiet Glade"
, "5_16 - Who might you be;"
, "5_17 - Petal Dance"
, "5_18 - Flying Feather"
, "5_19 - Sunset of Seven Suns"
, "5_20 - Shop 3"
, "5_21 - Violet Tactics"
, "5_22 - Flower King"
, "5_23 - Flower Foyer"
, "5_24 - Flower Castle"
, "5_25 - Thousand Cafe Zukan"
, "5_26 - I'm Telling!"
, "5_27 - Stop, Criminell!"
, "5_28 - Loving Steps"//found
, "5_29 - Onsen"
, "5_30 - Beautiful Bathtime"//
, "5_31 - Pink"
, "5_32 - Cutie Mew Mew Magic"
, "5_33 - Running Sky"
, "5_34 - Flower Man"
, "5_35 - That Day"
, "5_36 - Dreamwatchers"
, "5_37 - Weak Flowers"
, "5_38 - Walking Home"
, "5_39 - Field of Hopes and Dreams(From Piano Collections)"
, "5_40 - Goodnight, Sweet Prince"//dunno
}
};
std::string filename[CH][N_OST]={{ "AUDIO_ANOTHERHIM.ogg"
, "mus_introcar.ogg"
, "mus_school.ogg"
, "s_neo.ogg"
, "creepydoor.ogg"
, "creepylandscape.ogg"
, "creepychase.ogg"
, "legend.ogg"
, "lancer.ogg"
, "battle.ogg"
, "castletown_empty.ogg"
, "bird.ogg"
, "field_of_hopes.ogg"
, "fanfare.ogg"
, "shop1.ogg"
, "lancer_susie.ogg"
, "checkers.ogg"
, "quiet_autumn.ogg"
, "forest.ogg"
, "thrashmachine.ogg"
, "lancerfight.ogg"
, "basement.ogg"
, "tense.ogg"
, "vs_susie.ogg"
, "card_castle.ogg"
, "ruruskaado.ogg"
, "april_2012.ogg"
, "hip_shop.ogg"
, "GALLERY.ogg"
, "kingboss.ogg"
, "AUDIO_DARKNESS.ogg"
, "prejoker.ogg"
, "joker.ogg"
, "friendship.ogg"
, "THE_HOLY.ogg"
, "!snd_usefountain.ogg "
, "town.ogg"
, "home.ogg"
, "dontforget.ogg"
, "AUDIO_STORY.ogg"
}
,{ "menu.ogg"
, "noelle_school.ogg"
, "castletown.ogg"
, "queen_intro.ogg"
, "queen.ogg"
, "cyber.ogg"
, "boxing_game.ogg"
, "cyber_battle_prelude.ogg"
, "music_guys_intro.ogg"
, "music_guys.ogg"
, "cyber_battle.ogg"
, "cyber_battle_end.ogg"
, "cyber_shop.ogg"
, "berdly_theme.ogg"
, "berdly_chase.ogg"
, "AUDIO_DEFEAT.ogg"
, "cybercity.ogg"
, "cyberhouse.ogg"
, "cybershop_christmas.ogg"
, "queen_car_radio.ogg"
, "spamton_meeting_intro.ogg"
, "spamton_meeting.ogg"
, "spamton_battle.ogg"
, "mansion_entrance.ogg"
, "berdly_flashback.ogg"
, "mansion.ogg"
, "KEYGEN.ogg"
, "acid_tunnel.ogg"
, "rouxls_battle.ogg"
, "noelle_normal.ogg"
, "noelle_ferriswheel.ogg"
, "queen_boss.ogg"
, "giant_queen_appears.ogg"
, "gigaqueen_pre.ogg"
, "boxing_boss.ogg"
, "the_dark_truth.ogg"
, "spamton_basement.ogg"
, "spamton_neo_meeting.ogg"
, "spamton_neo_mix_ex_wip.ogg"
, "spamton_happy.ogg"
, "spamton_neo_after.ogg"
, "muscle.ogg"
, "napsta_alarm.ogg"
, "home.ogg"
, "ch2_credits.ogg"
, "AUDIO_STORY.ogg"
, ""   //the unused Berdly concept
}
};
int main()
{

    fstream fd("DELTARUNE_DIRECTORY.txt");
    string delta_path;

    if(!fd.is_open())
    {
        printf("Path to Deltarune Not Found\n");
        printf("Close This Programm,copy the path to the deltarune directory in the file:\n");
        printf("[DELTARUNE_DIRECTORY]\nAnd then reopen the programm\n");
        printf("By the way please run this exe in a new folder");
        fopen("DELTARUNE_DIRECTORY.txt","w");
        getchar();
        return 0;
    }
    getline(fd,delta_path);
    fd.close();
    c2cpp_path(delta_path);
    string path_demo=delta_path+"/snd_usefountain.ogg";
    if(fopen(path_demo.c_str(),"r")==NULL)
        filesystem::copy_file(delta_path+"/chapter1_windows/snd_usefountain.ogg","1_36 - Your Power.ogg");
    else
        filesystem::copy_file(path_demo,"1_36 - Your Power.ogg");
    int i=0,j=0,stat;
    std::string f,o,n="0";

    for(i=0;i<MAXCH;i++){
        for(j=0;j<n_ost[i];j++){
            if(i==0 && j==35||i==1 && j==46)//exceptions for your poewr and rejected berdly
                continue;
            f=filename[i][j];
            o=ostname[i][j];
            printf("renaming %-30s to %-55s ",f.c_str(),o.c_str());
            f=delta_path+"/mus/"+filename[i][j];
            o=ostname[i][j]+".ogg";
            filesystem::copy_file(f,o);
            printf("->STAT:%-d\n",stat);

        }
    }
    cout<<"Done renaming!Press enter to exit!\n Have fun :)";
    getchar();
    return 0;
}

void c2cpp_path(std::string &str)//replaces '\' with '/'
{
    int i;
    for(i=0;str[i]!='\0'&&str[i]!='\n';i++){
        if(str[i]=='\\')
            str[i]='/';
    }
}
