#pragma once

//#include<iostream>
#include<string>
#include<Windows.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include"dirent.h"
#include"MyForm.h"
#include<vector>

using namespace std;

vector <string> USBarr;
vector <string> CDarr;
vector <string> USBplaylist;
vector <string> CDplaylist;
int listSizeUSB = 0;
int listSizeCD = 0;
int dirSizeUSB;
int dirSizeCD;

class Audio_Player
{
protected:
	string manufac_name;
	int model_no;
	bool Power;
public:
	Audio_Player(string manu_n = "", int mod_no = 0) :manufac_name(manu_n), model_no(mod_no), Power(0)
	{}
	virtual void PowerON() = 0;
	virtual void PowerOFF() = 0;
	virtual void setmanufac_name(string manu_n) = 0;
	virtual void setModel_no(int mod_no) = 0;
	virtual string getname() = 0;
	virtual	int getmodel_no() = 0;
	virtual string PlayMusicUSB() = 0;
	virtual string PlayMusicCD() = 0;
};

class StorageDevice
{
protected:
	bool Mounted;
	int CounterCD;
	int CounterUSB;
public:
	StorageDevice();
	void setmount(bool m);
	bool getmount();
	void setCounterCD(int k);
	int getCounterCD();
	void setCounterUSB(int k);
	int getCounterUSB();
	void CheckSize();
	void CheckFileType();
	void mounted();
	void UnMounted();
};
StorageDevice::StorageDevice() :Mounted(0), CounterCD(0), CounterUSB(0) {}
void StorageDevice::setmount(bool m)
{
	Mounted = m;
}
bool StorageDevice::getmount()
{
	return Mounted;
}
void StorageDevice::setCounterCD(int k) { CounterCD = k; }
int StorageDevice::getCounterCD() { return CounterCD; }
void StorageDevice::setCounterUSB(int k) { CounterUSB = k; }
int StorageDevice::getCounterUSB() { return CounterUSB; }
void StorageDevice::CheckSize()
{

}
void StorageDevice::CheckFileType()
{

}
void StorageDevice::mounted()
{
	Mounted = 1;
	CheckSize();
	CheckFileType();
}
void StorageDevice::UnMounted()
{
	Mounted = 0;
}

class In_Car_AP :public Audio_Player
{
	StorageDevice stdv;
public:
	In_Car_AP();
	void PowerON();
	void PowerOFF();
	void setmanufac_name(string manu_n);
	void setModel_no(int mod_no);
	string getname();
	int getmodel_no();
	string PlayMusicUSB();
	string PauseMusicUSB();
	string NextMusicUSB();
	string PreviousMusicUSB();
	string ShuffleUSB();
	void CloseMusicUSB();
	int GetIndexUSB(string);
	string PlayMusicCD();
	string PauseMusicCD();
	string NextMusicCD();
	string PreviousMusicCD();
	string ShuffleCD();
	void CloseMusicCD();
	int GetIndexCD(string);
	void RandomPlay(int);
};
In_Car_AP::In_Car_AP() {}
void In_Car_AP::PowerON()
{
	Power = 1;
}
void In_Car_AP::PowerOFF()
{
	Power = 0;
}
void In_Car_AP::setmanufac_name(string manu_n)
{
	manufac_name = manu_n;
}
void In_Car_AP::setModel_no(int mod_no)
{
	model_no = mod_no;
}
string In_Car_AP::getname()
{
	return manufac_name;
}
int In_Car_AP::getmodel_no()
{
	return model_no;
}
string In_Car_AP::PlayMusicUSB()
{
	string str= USBplaylist[stdv.getCounterUSB()] + " is Playing Now!!";
	string cmd = "play .\\USB\\" + USBplaylist[stdv.getCounterUSB()];
	mciSendStringA(cmd.c_str(), NULL, 0, NULL);
	return str;
}
string In_Car_AP::PauseMusicUSB()
{
	string str = USBplaylist[stdv.getCounterUSB()] + " is Paused Now!!";
	string cmd = "pause .\\USB\\" + USBplaylist[stdv.getCounterUSB()];
	mciSendStringA(cmd.c_str(), NULL, 0, NULL);
	return str;
}
string In_Car_AP::NextMusicUSB()
{
	CloseMusicUSB();
	if (stdv.getCounterUSB() >= (listSizeUSB - 1))
	{
		string s = PlayMusicUSB();
		return s;
	}
	else
	{
		stdv.setCounterUSB(stdv.getCounterUSB() + 1);
		string s = PlayMusicUSB();
		return s;
	}
}
string In_Car_AP::PreviousMusicUSB()
{
	CloseMusicUSB();
	if (stdv.getCounterUSB() <= 0)
	{
		string s = PlayMusicUSB();
		return s;
	}
	else
	{
		stdv.setCounterUSB(stdv.getCounterUSB() - 1);
		string s = PlayMusicUSB();
		return s;
	}
}
string In_Car_AP::ShuffleUSB()
{
	CloseMusicUSB();
	stdv.setCounterUSB(rand() % listSizeUSB);
	string s = PlayMusicUSB();
	return s;
}
void In_Car_AP::CloseMusicUSB()
{
	string cmd = "close .\\USB\\" + USBplaylist[stdv.getCounterUSB()];
	mciSendStringA(cmd.c_str(), NULL, 0, NULL);
}
int In_Car_AP::GetIndexUSB(string s)
{
	string onlyname = s.substr(0, s.length() - 17);
	for (int i = 0; i < listSizeUSB; i++)
	{
		if (onlyname == USBplaylist[i])
		{
			return i;
		}
	}
}

string In_Car_AP::PlayMusicCD()
{
	string str = CDplaylist[stdv.getCounterCD()] + " is Playing Now!!";
	//cout << endl << ptr[stdv.getCounter()] << " is Playing Now!!\n\n";
	string cmd = "play .\\CD\\" + CDplaylist[stdv.getCounterCD()];
	mciSendStringA(cmd.c_str(), NULL, 0, NULL);
	return str;
}
string In_Car_AP::PauseMusicCD()
{
	string str = CDplaylist[stdv.getCounterCD()] + " is Paused Now!!";
	string cmd = "pause .\\CD\\" + CDplaylist[stdv.getCounterCD()];
	mciSendStringA(cmd.c_str(), NULL, 0, NULL);
	return str;
}
string In_Car_AP::NextMusicCD()
{
	CloseMusicCD();
	if (stdv.getCounterCD() >= (listSizeCD - 1))
	{
		string s = PlayMusicCD();
		return s;
	}
	else
	{
		stdv.setCounterCD(stdv.getCounterCD() + 1);
		string s = PlayMusicCD();
		return s;
	}
}
string In_Car_AP::PreviousMusicCD()
{
	CloseMusicCD();
	if (stdv.getCounterCD() <= 0)
	{
		string s = PlayMusicCD();
		return s;
	}
	else
	{
		stdv.setCounterCD(stdv.getCounterCD() - 1);
		string s = PlayMusicCD();
		return s;
	}
}
string In_Car_AP::ShuffleCD()
{
	CloseMusicCD();
	stdv.setCounterCD(rand() % listSizeCD);
	string s = PlayMusicCD();
	return s;
}
void In_Car_AP::CloseMusicCD()
{
	string cmd = "close .\\CD\\" + CDplaylist[stdv.getCounterCD()];
	mciSendStringA(cmd.c_str(), NULL, 0, NULL);
}
int In_Car_AP::GetIndexCD(string s)
{
	string onlyname = s.substr(0, s.length() - 17);
	for (int i = 0; i < listSizeCD; i++)
	{
		if (onlyname == CDplaylist[i])
		{
			return i;
		}
	}
}
void In_Car_AP::RandomPlay(int index)
{
}

class USB :public StorageDevice
{
public:
	USB();
	void openUSB();
	void SavePlayListUSB(string);
};
USB::USB() {}
void USB::openUSB()
{
	int size = 0;
	string path2 = "./USB";
	DIR* dirusb = opendir(path2.c_str());
	struct dirent* entity2 = NULL;
	while (entity2 = readdir(dirusb))
	{
		string usb = entity2->d_name;
		if (usb.length() > 4)
		{
			string s2 = usb.substr(usb.length() - 4, usb.length());
			if (s2 == ".mp3")
			{
				USBarr.push_back(usb);
				size++;
				if ((size - 1) > 4300)
				{
				}
			}
		}
	}
	dirSizeUSB = size;
	closedir(dirusb);
}
void USB::SavePlayListUSB(string s)
{
	static fstream fileUSB;
	fileUSB.open("PlayListUSB.txt", ios::out | ios::app);
	fileUSB << s << endl;
	listSizeUSB++;
	fileUSB.close();
}

class CD :public StorageDevice
{
public:
	void openCD();
	void SavePlayListCD(string);
};
void CD::openCD()
{
	int size = 0;
	string path = "./CD";
	DIR* dircd = opendir(path.c_str());
	struct dirent* entity = NULL;
	//cout << "******CD Directry******\n";
	while (entity = readdir(dircd))
	{
		string cd = entity->d_name;
		if (cd.length() > 4)
		{
			string s1 = cd.substr(cd.length() - 4, cd.length());
			if (s1 == ".mp3")
			{
				CDarr.push_back(cd);
				size++;
				if ((size - 1) > 130)
				{
				}
			}
		}
	}
	dirSizeCD = size;
	closedir(dircd);
}
void CD::SavePlayListCD(string s)
{
	static fstream fileCD;
	fileCD.open("PlayListCD.txt", ios::out | ios::app);
	fileCD << s << endl;
	listSizeCD++;
	fileCD.close();
}