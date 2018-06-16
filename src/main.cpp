/// MIDI to JSON converter
// This program uses midifile.sapp.org library

#include "midi/MidiFile.h"
#include "midi/MidiEvent.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
///#include <windows.h>
unsigned x=1;
int dtick;
int dchannel;
void Askforw()
{
    std::cout << "MIDI tick for Q: " << std::flush;
    std::cin >> x;
}
void Askfordouble()
{
    std::cout << "MIDI track for 5<> (0 to disable): " << std::flush;
    std::cin >> dchannel;
    if (dchannel==0)
        return;
    std::cout << "MIDI tick for 5<>: " << std::flush;
    std::cin >> dtick;
}
void Message(const std::string & text,bool iserror=false)
{
    std::cout << text << std::endl;
    if (iserror)
        abort();
}
unsigned sd(unsigned & a,unsigned b)
{
    if (b==0)
    {
        Message("Dividing by zero.",true);
    }
    else
    {
        unsigned c=a/b;
        if (c*b==a)
        {
            a = c;
            return c;
        }
        else
        {
            Message("Dividing error.",true);
        }
    }
    return 0;
}
std::string GetFilename(const std::string & text)
{
    std::string fname;
    std::cout << text << std::flush;
    std::getline(std::cin,fname);
    fname.erase(remove(fname.begin(),fname.end(),'"'),fname.end());
    return fname;
}
std::string Checkn(int n)
{
    if (n==108)
        return "c5";
    else if (n==107)
        return "b4";
    else if (n==106)
        return "#a4";
    else if (n==105)
        return "a4";
    else if (n==104)
        return "#g4";
    else if (n==103)
        return "g4";
    else if (n==102)
        return "#f4";
    else if (n==101)
        return "f4";
    else if (n==100)
        return "e4";
    else if (n==99)
        return "#d4";
    else if (n==98)
        return "d4";
    else if (n==97)
        return "#c4";
    else if (n==96)
        return "c4";
    else if (n==95)
        return "b3";
    else if (n==94)
        return "#a3";
    else if (n==93)
        return "a3";
    else if (n==92)
        return "#g3";
    else if (n==91)
        return "g3";
    else if (n==90)
        return "#f3";
    else if (n==89)
        return "f3";
    else if (n==88)
        return "e3";
    else if (n==87)
        return "#d3";
    else if (n==86)
        return "d3";
    else if (n==85)
        return "#c3";
    else if (n==84)
        return "c3";
    else if (n==83)
        return "b2";
    else if (n==82)
        return "#a2";
    else if (n==81)
        return "a2";
    else if (n==80)
        return "#g2";
    else if (n==79)
        return "g2";
    else if (n==78)
        return "#f2";
    else if (n==77)
        return "f2";
    else if (n==76)
        return "e2";
    else if (n==75)
        return "#d2";
    else if (n==74)
        return "d2";
    else if (n==73)
        return "#c2";
    else if (n==72)
        return "c2";
    else if (n==71)
        return "b1";
    else if (n==70)
        return "#a1";
    else if (n==69)
        return "a1";
    else if (n==68)
        return "#g1";
    else if (n==67)
        return "g1";
    else if (n==66)
        return "#f1";
    else if (n==65)
        return "f1";
    else if (n==64)
        return "e1";
    else if (n==63)
        return "#d1";
    else if (n==62)
        return "d1";
    else if (n==61)
        return "#c1";
    else if (n==60)
        return "c1";
    else if (n==59)
        return "b";
    else if (n==58)
        return "#a";
    else if (n==57)
        return "a";
    else if (n==56)
        return "#g";
    else if (n==55)
        return "g";
    else if (n==54)
        return "#f";
    else if (n==53)
        return "f";
    else if (n==52)
        return "e";
    else if (n==51)
        return "#d";
    else if (n==50)
        return "d";
    else if (n==49)
        return "#c";
    else if (n==48)
        return "c";
    else if (n==47)
        return "B-1";
    else if (n==46)
        return "#A-1";
    else if (n==45)
        return "A-1";
    else if (n==44)
        return "#G-1";
    else if (n==43)
        return "G-1";
    else if (n==42)
        return "#F-1";
    else if (n==41)
        return "F-1";
    else if (n==40)
        return "E-1";
    else if (n==39)
        return "#D-1";
    else if (n==38)
        return "D-1";
    else if (n==37)
        return "#C-1";
    else if (n==36)
        return "C-1";
    else if (n==35)
        return "B-2";
    else if (n==34)
        return "#A-2";
    else if (n==33)
        return "A-2";
    else if (n==32)
        return "#G-2";
    else if (n==31)
        return "G-2";
    else if (n==30)
        return "#F-2";
    else if (n==29)
        return "F-2";
    else if (n==28)
        return "E-2";
    else if (n==27)
        return "#D-2";
    else if (n==26)
        return "D-2";
    else if (n==25)
        return "#C-2";
    else if (n==24)
        return "C-2";
    else if (n==23)
        return "B-3";
    else if (n==22)
        return "#A-3";
    else if (n==21)
        return "A-3";
    else
        Message("Wrong note range.",true);
    return "ERROR";
}
std::string Checkd(unsigned t,bool mode)
{
    std::string result;
    if (mode==0)
    {
        while (true)
        {
            unsigned w=x;
            if (t>=w)
            {
                t -= w;
                result+='H';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='I';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='J';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='K';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='L';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='M';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='N';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='O';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='P';
            }
            else if (t<w)
                Message("Wrong length value.",true);
            if (t==0)
                break;
        }
    }


    if (mode==1)
    {
        while (true)
        {
            unsigned w=x;
            if (t>=w)
            {
                t -= w;
                result+='Q';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='R';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='S';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='T';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='U';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='V';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='W';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='X';
            }
            else if (t>=sd(w,2))
            {
                t -= w;
                result+='Y';
            }
            else if (t<w)
                Message("Wrong length value.",true);
            if (t==0)
                break;
        }
    }
    return result;
}

class plik
{
    MidiFile m;
public:
    plik()
    {
        do
        {
            m.read(GetFilename("MIDI file < "));
        }
        while (m.status()!=1);

        m.linkNotePairs();
        if (m.getTrackCount()<1)
        {
            Message("Wrong track number value.",true);

        }
        m.deltaTicks();



        Askforw();
        Askfordouble();
        std::ofstream logfile("log.txt");
        for (int trak=0; trak<m.getTrackCount(); ++trak)
        {
            logfile << std::endl << std::endl << "TRACK " << trak+1 << ":" << std::endl<<std::endl;
            int evc = m.getEventCount(trak);
            MidiEvent e;
            int notes=0;
            std::vector<int> notevalues;
            int lastontick=0;
            int lastduration=0;
            bool doubler=0;

            for (int i=0; i<evc; ++i)
            {
                e = m.getEvent(trak,i);

                if (e.isNoteOn())
                {
                    if (lastontick==0)
                        lastontick=i;
                    ++notes;
                    notevalues.push_back(e.getKeyNumber());
                }
                else if (e.isNoteOff())
                {
                    if (lastduration==0)
                        lastduration=m[trak][i].tick;
                    --notes;
                    if (notes==0)
                    {
                        if (trak+1==dchannel&&lastduration==dtick&&doubler==0)
                        {
                            logfile<<"5<";
                        }
                        if (m[trak][lastontick].tick!=0)
                        {
                            if (doubler==1)
                                Message("Rest within 5<>!",true);
                            logfile<<Checkd(m[trak][lastontick].tick,1)+',';
                        }
                        if (notevalues.size()==1)
                        {
                            logfile << Checkn(notevalues[0]);
                        }
                        else
                        {
                            logfile << "(";
                            for (unsigned x=0; x<notevalues.size(); ++x)
                            {
                                logfile << Checkn(notevalues[x]);
                                if (x+1<notevalues.size())
                                    logfile << ".";
                            }
                            logfile << ")";
                        }
                        logfile << "["+Checkd(lastduration,0)+"]";
                        if (trak+1==dchannel&&lastduration==dtick)
                        {
                            doubler = !doubler;
                            if (doubler==0)
                            {
                                logfile<<">";
                            }
                        }
                        else if (doubler==1)
                            Message("Fatal error with 5<>!",true);
                        logfile << ",";
                        notevalues.clear();

                        lastduration=0;
                        lastontick=0;
                    }
                }

                logfile<<std::flush;
            }
        }
    }
};
int main()
{
    plik p;
    ///ShellExecute(0, 0, "log.txt", 0, 0 , SW_SHOWMAXIMIZED );
    return 0;
}
