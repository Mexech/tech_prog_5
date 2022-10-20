#include "Factory.h"

using namespace std;

class Furniture: public Factory {
    private:
        string type;
        float height;
        float width;
        float depth;
        string color;
        string material;
        float cost;
    public:
        Furniture();
        Furniture(string type, float height, float width, float depth, string color, string material, float cost);
        Furniture(const Furniture &o);
        ~Furniture();

        void setType(string s);
        string getType();
        void setHeight(float n);
        float getHeight();
        void setWidth(float n);
        float getWidth();
        void setDepth(float n);
        float getDepth();
        void setColor(string s);
        string getColor();
        void setMaterial(string s);
        string getMaterial();
        void setCost(float n);
        float getCost();

        string getFactoryType();
        string getParams();
        string getFormattedParams();
        void edit();

        friend istream& operator>>(istream &is, Furniture &o);
};