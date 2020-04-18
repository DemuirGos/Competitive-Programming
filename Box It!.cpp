
class Box{
    public:
        int w,h,d;
        Box(){
            w=h=d=0;
        }
        Box(int a,int b,int c){
            d=a;w=b;h=c;
        }
        Box(Box* b){
            w=b->w;h=b->h;d=b->d;
        }
        int getLength(){
            return d;
        }
        int getBreadth(){
            return w;
        }
        int getHeight(){
            return h;
        }
        long long CalculateVolume(){
            return (long long)d*w*h;
        }
        friend bool operator<(Box& a,Box& b){
            if((a.d<b.d) || (a.d==b.d && a.w<b.w) ||(a.d==b.d && a.w==b.w && a.h<b.h))
                return 1;
            return 0;
        }
        friend ostream& operator<<(ostream& out,Box& b){
            out << b.d << " " << b.w << " " << b.h;
            return out;
        }
};
