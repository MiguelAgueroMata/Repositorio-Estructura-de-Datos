#ifndef BUILDINGSTRUCTURES
#include <iostream>
#include <string>

using namespace std;


class Wall
{
    private:
        int wallLength;
        int wallHeight;
        string wallMaterial;
        string wallColor;

    public:
        void getWallSpecifications(int wLength, int wHeight, string wMaterial, string wColor)
        {
            wallLength = wLength;
            wallHeight = wHeight;
            wallMaterial = wMaterial;
            wallColor = wColor;
        }

};

class DoorWall
{
    private:
        int wallLength;
        int wallHeight;
        string wallMaterial;
        string wallColor;

        int doorHeight;
        int doorLength;
        string doorMaterial;

     public:
        void getWallDoorSpecifications(int wLength, int wHeight, string wMaterial, string wColor, int dHeight, int dLength, string dMaterial)
        {
            wallLength = wLength;
            wallHeight = wHeight;
            wallMaterial = wMaterial;
            wallColor = wColor;
            doorHeight = dHeight;
            doorLength = dLength;
            doorMaterial = dMaterial;
        }

};

class Balcony
{
    private:
        int balconyLength;
        int balconyWidth;

     public:
        void getBalconySpecifications(int bLength, int bWidth)
        {
            balconyLength = bLength;
            balconyWidth = bWidth;
        }
};

class Floor
{
    private:
        string floorMaterial;
        string floorColor;

    public:
        void getFloorSpecifications(string fMaterial, string fColor)
        {
            floorMaterial = fMaterial;
            floorColor = fColor;
        }
    
};

class Stairs
{
    private:
        string stairsColors;
        string stairsMaterial;

    public:
        void getStarisSpecifications(string sColors, string sMaterial)
        {
            stairsColors = sColors;
            stairsMaterial = sMaterial;
        }
    
};
#endif