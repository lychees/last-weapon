#ifndef LASTWEAPON_GEOMETRY_HPP
#define LASTWEAPON_GEOMETRY_HPP 1
#include "lastweapon/io"
inline DB cos(DB a, DB b, DB c){return (sqr(a)+sqr(b)-sqr(c))/(2*a*b);}
inline DB cot(DB x){return 1./tan(x);};
inline DB sec(DB x){return 1./cos(x);};
inline DB csc(DB x){return 1./sin(x);};
namespace lastweapon {
namespace CG {

#define cPo const Po&
#define cLine const Line&
#define cSeg const Seg&

    inline DB dist2(DB x,DB y){return sqr(x)+sqr(y);}

    struct Po{
        DB x,y;Po(DB x=0,DB y=0):x(x),y(y){}

        void in(){RF(x,y);}void out(){printf("(%.2f,%.2f)",x,y);}
        inline friend istream&operator>>(istream&i,Po&p){return i>>p.x>>p.y;}
        inline friend ostream&operator<<(ostream&o,Po p){return o<<"("<<p.x<<", "<<p.y<< ")";}

        Po operator-()const{return Po(-x,-y);}
        Po&operator+=(cPo p){x+=p.x,y+=p.y;rTs;}Po&operator-=(cPo p){x-=p.x,y-=p.y;rTs;}
        Po&operator*=(DB k){x*=k,y*=k;rTs;}Po&operator/=(DB k){x/=k,y/=k;rTs;}
        Po&operator*=(cPo p){rTs=Ts*p;}Po&operator/=(cPo p){rTs=Ts/p;}
        Po operator+(cPo p)const{return Po(x+p.x,y+p.y);}Po operator-(cPo p)const{return Po(x-p.x,y-p.y);}
        Po operator*(DB k)const{return Po(x*k,y*k);}Po operator/(DB k)const{return Po(x/k,y/k);}
        Po operator*(cPo p)const{return Po(x*p.x-y*p.y,y*p.x+x*p.y);}Po operator/(cPo p)const{return Po(x*p.x+y*p.y,y*p.x-x*p.y)/p.len2();}

        bool operator==(cPo p)const{return!sgn(x,p.x)&&!sgn(y,p.y);};bool operator!=(cPo p)const{return sgn(x,p.x)||sgn(y,p.y);}
        bool operator<(cPo p)const{return sgn(x,p.x)<0||!sgn(x,p.x)&&sgn(y,p.y)<0;}bool operator<=(cPo p)const{return sgn(x,p.x)<0||!sgn(x,p.x)&&sgn(y,p.y)<=0;}
        bool operator>(cPo p)const{return!(Ts<=p);}bool operator >=(cPo p)const{return!(Ts<p);}

        DB len2()const{return dist2(x,y);}DB len()const{return sqrt(len2());}DB arg()const{return atan2(y,x);}
        Po&_1(){rTs/=len();}Po&conj(){y=-y;rTs;}Po&lt(){swap(x,y),x=-x;rTs;}Po&rt(){swap(x,y),y=-y;rTs;}
        Po&rot(DB a,cPo o=Po()){Ts-=o;Ts*=Po(cos(a),sin(a));rTs+=o;}


        // 求所在象限，大部分情况下只区分两个足够。
        inline int q()const{
            return (y > 0 || y == 0 && x >= 0) ? 0 : 1;
            /*if (x > 0 && y >= 0) return 0;
             if (x <= 0 && y > 0) return 1;
             if (x < 0 && y <= 0) return 2;
             return 3;*/
        }
    };

    inline DB dot(DB x1,DB y1,DB x2,DB y2){return x1*x2+y1*y2;}
    inline DB dot(cPo a,cPo b){return dot(a.x,a.y,b.x,b.y);}
    inline DB dot(cPo p0,cPo p1,cPo p2){return dot(p1-p0,p2-p0);}
    inline DB det(DB x1,DB y1,DB x2,DB y2){return x1*y2-x2*y1;}
    inline DB det(cPo a,cPo b){return det(a.x,a.y,b.x,b.y);}
    inline DB det(cPo p0,cPo p1,cPo p2){return det(p1-p0,p2-p0);}
    inline DB ang(cPo p0,cPo p1){return acos(dot(p0,p1)/p0.len()/p1.len());}
    inline DB ang(cPo p0,cPo p1,cPo p2){return ang(p1-p0,p2-p0);}
    inline DB ang(cPo p0,cPo p1,cPo p2,cPo p3){return ang(p1-p0,p3-p2);}
    inline DB dist2(const Po &a, const Po &b){return dist2(a.x-b.x, a.y-b.y);}
    template<class T1, class T2> inline int dett(const T1 &x, const T2 &y){return sgn(det(x, y));}
    template<class T1, class T2, class T3> inline int dett(const T1 &x, const T2 &y, const T3 &z){return sgn(det(x, y, z));}
    template<class T1, class T2, class T3, class T4> inline int dett(const T1 &x, const T2 &y, const T3 &z, const T4 &w){return sgn(det(x, y, z, w));}
    template<class T1, class T2> inline int dott(const T1 &x, const T2 &y){return sgn(dot(x, y));}
    template<class T1, class T2, class T3> inline int dott(const T1 &x, const T2 &y, const T3 &z){return sgn(dot(x, y, z));}
    template<class T1, class T2, class T3, class T4> inline int dott(const T1 &x, const T2 &y, const T3 &z, const T4 &w){return sgn(dot(x, y, z, w));}
    template<class T1, class T2> inline DB arg(const T1 &x, const T2 &y){DB a=ang(x,y);return~dett(x,y)?a:2*PI-a;}
    template<class T1, class T2, class T3> inline DB arg(const T1 &x, const T2 &y, const T3 &z){DB a=ang(x,y,z);return~dett(x,y,z)?a:2*PI-a;}
    template<class T1, class T2, class T3, class T4> inline DB arg(const T1 &x, const T2 &y, const T3 &z, const T4 &w){DB a=ang(x,y,z,w);return~dett(x,y,z,w)?a:2*PI-a;}
    template<class T1, class T2> inline DB dist(const T1 &x, const T2 &y){return sqrt(dist2(x, y));}
    template<class T1, class T2, class T3> inline DB dist(const T1 &x, const T2 &y, const T3 &z){return sqrt(dist2(x, y, z));}
    inline Po _1(Po p){return p._1();}inline Po conj(Po p){return p.conj();}
    inline Po lt(Po p){return p.lt();}inline Po rt(Po p){return p.rt();}
    inline Po rot(Po p,DB a,cPo o=Po()){return p.rot(a,o);}
    inline Po operator *(DB k,cPo p){return p*k;}
    inline Po operator /(DB k,cPo p){return conj(p)*k/p.len2();}

    typedef vector<Po> VP;

    struct Line{
        Po a,b;Line(cPo a=Po(),cPo b=Po()):a(a),b(b){}
        Line(DB x0,DB y0,DB x1,DB y1):a(Po(x0,y0)),b(Po(x1,y1)){}
        Line(cLine l):a(l.a),b(l.b){}

        //Ax+By+C=0
        Line(DB A,DB B,DB C){
            C=-C;if(!::sgn(A))a=Po(0,C/B),b=Po(1,C/B);
            else if(!::sgn(B))a=Po(C/A,0),b=Po(C/A,1);
            else a=Po(0,C/B),b=Po(1,(C-A)/B);
        }

        void in(){a.in(),b.in();}
        inline friend istream&operator>>(istream&i,Line& p){return i>>p.a>>p.b;}
        inline friend ostream&operator<<(ostream&o,Line p){return o<<p.a<<"-"<< p.b;}

        Line operator+(cPo x)const{return Line(a+x,b+x);}
        Line operator-(cPo x)const{return Line(a-x,b-x);}
        Line operator*(DB k)const{return Line(a*k,b*k);}
        Line operator/(DB k)const{return Line(a/k,b/k);}

        Po operator*(cLine)const;
        Po d()const{return b-a;}DB len2()const{return d().len2();}DB len()const{return d().len();}DB arg()const{return d().arg();}

        int sgn(cPo p)const{return dett(a, b, p);}
        int sgn(cLine)const;

        bool sameSgn(cPo  p1,cPo  p2)const{return sgn(p1)==sgn(p2);}
        void getEquation(DB&K,DB&B)const{
            K = ::sgn(a.x, b.x) ? (b.y-a.y)/(b.x-a.x) : OO;
            B = a.y - K*a.x;
        }
        void getEquation(DB&A,DB&B,DB&C)const{A=a.y-b.y,B=b.x-a.x,C=det(a, b);}

        Line&push(DB r){ // 正数右手螺旋向里
            Po v=d()._1().lt()*r;a+=v,b+=v; rTs;
        }
    };

    inline DB dot(cLine l1,cLine l2){return dot(l1.d(),l2.d());}
    inline DB dot(cLine l,cPo p){return dot(l.a,l.b,p);}
    inline DB dot(cPo p,cLine l){return dot(p,l.a,l.b);}
    inline DB det(cLine l1,cLine l2){return det(l1.d(),l2.d());}
    inline DB det(cLine l,cPo p){return det(l.a,l.b,p);}
    inline DB det(cPo p,cLine l){return det(p,l.a,l.b);}
    inline DB ang(cLine l0,cLine l1){return ang(l0.d(),l1.d());}
    inline DB ang(cLine l,cPo p){return ang(l.a,l.b,p);}
    inline DB ang(cPo p,cLine l){return ang(p,l.a,l.b);}

    inline int Line::sgn(cLine l)const{return dett(Ts, l);}
    inline Po Line::operator*(cLine l)const{return a+d()*det(a,l)/det(Ts,l);}
    inline Po operator&(cPo p,cLine l){return l*Line(p,p+l.d().lt());}
    inline Po operator%(cPo p,cLine l){return p&l*2-p;}
    inline Line push(Line l, DB r){return l.push(r);}


    struct Seg: public Line{
        Seg(cPo a=Po(),cPo b=Po()):Line(a,b){}
        Seg(DB x0,DB y0,DB x1,DB y1):Line(x0,y0,x1,y1){}
        Seg(cLine l):Line(l){}
        Seg(const Po &a,DB alpha):Line(a,alpha){}
        Seg(DB A,DB B,DB C):Line(A,B,C){}

        inline int sgn(cPo p)const;
        inline int sgn(cLine l)const;
        inline bool qrt(cSeg l)const;
        inline int sgn(cSeg l)const;
    };

    // -1不相交 0相交（不规范） 1相交（规范）

    //inline int Seg::sgn(cPo p)const{return -dott(p,a,b);}

    inline int Seg::sgn(cPo p)const{
        if (dett(p, a, b)) return -1; // 有时会有精度误差。。
        if (a == p || b == p) return 0;
        return -dott(p,a,b);
    }


    inline int Seg::sgn(cLine l)const{return sgn(Ts*l);}

    // quick_rejection_test
    inline bool Seg::qrt(cSeg l)const{
        return min(a.x,b.x)<=max(l.a.x,l.b.x)&&min(l.a.x,l.b.x)<=max(a.x,b.x)&&
        min(a.y,b.y)<=max(l.a.y,l.b.y)&&min(l.a.y,l.b.y)<=max(a.y,b.y);
    }


    inline int Seg::sgn(cSeg l)const{
        if (!qrt(l)) return -1;

        /*return
         (dett(a,b,l.a)*dett(a,b,l.b)<=0 &&
         dett(l.a,l.b,a)*dett(l.a,l.b,b)<=0)?1:-1;*/

        int d1=dett(a,b,l.a),d2=dett(a,b,l.b),d3=dett(l.a,l.b,a),d4=dett(l.a,l.b,b);
        if ((d1^d2)==-2&&(d3^d4)==-2)return 1;
        return ((!d1&&dott(l.a-a,l.a-b)<=0)||(!d2&&dott(l.b-a,l.b-b)<=0)||
                (!d3&&dott(a-l.a,a-l.b)<=0)||(!d4&&dott(b-l.a,b-l.b)<=0))?0:-1;
    }

    //inline DB dist2(cLine l,cPo p){return sqr(fabs(dot(lt(l.d()), p-l.a)))/l.len2();}
    inline DB dist2(cLine l,cPo p){return sqr(fabs(det(l.d(), p-l.a)))/l.len2();}

    inline DB dist2(cLine l1,cLine l2){return dett(l1,l2)?0:dist2(l1,l2.a);}

    inline DB dist2(cSeg l,cPo p){
        Po pa = p - l.a, pb = p - l.b;
        if (dott(l.d(), pa) <= 0) return pa.len2();
        if (dott(l.d(), pb) >= 0) return pb.len2();
        return dist2(Line(l), p);
    }


    inline DB dist2(cSeg s,cLine l){
        Po v1=s.a-l.a,v2=s.b-l.a;DB d1=det(l.d(),v1),d2=det(l.d(),v2);
        return sgn(d1)!=sgn(d2) ? 0 : sqr(min(fabs(d1), fabs(d2)))/l.len2();
    }
    inline DB dist2(cSeg l1,cSeg l2){
        if (~l1.sgn(l2)) return 0;
        else return min(dist2(l2,l1.a), dist2(l2,l1.b), dist2(l1,l2.a), dist2(l1,l2.b));
    }
    template<class T1, class T2> inline DB dist2(const T1& a, const T2& b){
        return dist2(b, a);
    }

    struct Triangle; struct Circle;
    typedef const Triangle&cTriangle; typedef const Circle&cCircle;

    const int Disjoint = -2, Exscribe = -1, Cross = 0, Inscribe = 1, Contain = 2;

    Po getX3(cPo a, cPo b, cPo c){ // 外接圆圆心
        Po v0=b-a,v1=c-a;DB l0=v0.len2(),l1=v1.len2(),d=2*det(a,b,c);
        return Po(l0*v1.y-l1*v0.y,l1*v0.x-l0*v1.x)/d+a;
        //Po v0 = b-a, v1 = c-a, m0 = (a+b)/2, m1 = (a+c)/2;
        //return Line(m0,m0+v0.lt())*Line(m1,m1+v1.lt());
    }




    Po getX4(cPo a, cPo b, cPo c){ // 垂心 // orthocenter
        return Line(a,a&Line(b,c))*Line(b,b&Line(a,c));
    }



    struct Circle{
        Po o; DB r; Circle(cPo o=Po(),DB r=0):o(o),r(r){}
        Circle(cPo a,cPo b):o((a+b)/2),r(dist(a,b)/2){}
        Circle(cLine l):Circle(l.a, l.b){}
        Circle(cPo a,cPo b,cPo c):o(getX3(a,b,c)),r(dist(o,a)){}

        void in(){o.in(),RF(r);}
        void out(){printf("%.2f %.2f %.2f\n", o.x, o.y, r);}

        bool operator <(cCircle c)const{return r<c.r;}
        //-1相离 0圆上 1包含
        inline int sgn(cPo p)const{return ::sgn(r*r, dist2(o, p));}
        //-1相离 0相切 1相交
        inline int sgn(cLine l)const{return ::sgn(r*r, dist2(l, o));}
        // -2外离 -1外切 0相交 1内切 2包含
        inline int sgn(cCircle c)const{
            DB d=dist2(o,c.o);
            if (::sgn(sqr(r+c.r),d)<0) return Disjoint;
            if (!::sgn(sqr(r+c.r), d)) return Exscribe;
            if (!::sgn(sqr(r-c.r), d)) return Inscribe;
            if (::sgn(sqr(r-c.r), d)>0) return Contain;
            return Cross;
        }

        inline DB s(){return PI*r*r;}
        inline DB p(){return 2*PI*r;}

        inline void getIntersect(cLine l,Po&p0,Po&p1)const{
            Po m = o&l, d = (l.b-l.a)._1() * sqrt(sqr(r)-dist2(l, o));
            p0 = m + d, p1 = m - d;
        }
        inline void getIntersect(cCircle c,Po&p0,Po&p1)const{
            Po v=(c.o-o)._1()*r;DB a=acos(cos(r,dist(o,c.o),c.r));
            p0=o+rot(v,a),p1=o+rot(v,-a);
        }

        inline void getTangency(cPo p,Po&p0,Po&p1)const{
            DB d=dist(o,p),a=acos(r/d);Po v=(p-o)._1()*r;
            p0=o+rot(v,a),p1=o+rot(v,-a);
        }

        inline VP operator*(cLine l)const{
            VP P; int t = sgn(l); if (t==-1) return P;
            Po p0, p1; getIntersect(l, p0, p1); P.PB(p0); if (t == 1) P.PB(p1);
            return P;
        }

        inline VP operator*(cSeg s)const{
            VP _P = Ts*Line(s), P; ECH(p, _P) if (~s.sgn(*p)) P.PB((*p));
            return P;
        }

        inline Po operator^(cCircle c)const{return Po(det(Po(o.x,r),Po(c.o.x,c.r)),det(Po(o.y,r),Po(c.o.y,c.r)))/(c.r-r);}

        inline VP operator*(cCircle c)const{
            VP P; int t = abs(sgn(c)); if (t == 2) return P;
            Po p0, p1; getIntersect(c, p0, p1); P.PB(p0); if (!t) P.PB(p1);
            return P;
        }
    };

    struct Triangle{
        Po A,B,C; DB a,b,c; DB alpha,beta,theta;
        DB r,R; DB S,P; Po I,G,O,H;

        void init(){
            S=fabs(det(A,B,C))/2,a=dist(B,C),b=dist(A,C),c=dist(A,B);
            alpha=acos(cos(b,c,a)),beta=acos(cos(a,c,b)),theta=acos(cos(a,b,c));
            P=a+b+c,R=(a*b*c)/(4*S),r=2*S/P;
            I=Po(a*A.x+b*B.x+c*C.x,a*A.y+b*B.y+c*C.y)/P;
            G=(A+B+C)/3,O=getX3(A,B,C),H=getX4(A,B,C);
            //DB s=P/2; assert(!sgn(S, sqrt(s*(s-a)*(s-b)*(s-c)))); // 海伦公式
            //assert(!sgn(dist(I,O), sqrt(R*(R-2*r))));
            //assert(!sgn(dist(H,G), dist(O,H)*2/3));
        }

        void in(){
            A.in(),B.in(),C.in();init();
        }
    };

    Po getPo(){Po p;p.in();return p;}
    Line getLine(){Line l;l.in();return l;}

    DB getArea(const VP& P){DB z=0;FOR(i,1,SZ(P))z+=det(P[i-1],P[i]);return z;}
    DB getPeri(const VP& P){DB z=0;FOR(i,1,SZ(P))z+=dist(P[i-1],P[i]);return z;}


    // 凸包
    VP getCH(VP& P, int b=1){ //逆时针，不保留共线

        int n=SZ(P); if(n<=3) return P.PB(P[0]),getArea(P)<0?RVS(P):P;

        SRT(P); VP C; C.resize(2*n+9); int nn = -1; REP(i, n){ //#
            while (nn > 0 && dett(C[nn-1], C[nn], P[i]) < b) --nn; //#
            C[++nn] = P[i];
        }

        int _nn = nn; DWN(i, n-1, 0){
            while (nn > _nn && dett(C[nn-1], C[nn], P[i]) < b) --nn; //#
            C[++nn] = P[i];
        }

        C.resize(nn+1);
        return C;
    }


    // 半平面交

    const int HPI_N = 109;

    bool cmpHPI(cLine l,cLine r){
        int t = sgn(l.arg(), r.arg()); if (!t) t = dett(r.a,l);
        return t < 0;
    }

    Line Q[HPI_N]; int cz, op;

    void cut_b(cLine l){while(cz<op&&dett(l,Q[op]*Q[op-1])<0)--op;}
    void cut_f(cLine l){while(cz<op&&dett(l,Q[cz]*Q[cz+1])<0)++cz;}
    void cut(cLine l){cut_b(l),cut_f(l),Q[++op]=l;}

    VP getHPI(vector<Line>&L){
        SRT(L, cmpHPI); int n = 1; FOR(i, 1, SZ(L)) if (sgn(L[i-1].arg(), L[i].arg())) L[n++] = L[i];
        VP P; cz = 0, op = 1, Q[0] = L[0], Q[1] = L[1]; FOR(i, 2, n){
            if (!dett(Q[op],Q[op-1])||!dett(Q[cz],Q[cz+1])) return P;
            cut(L[i]);
        }
        cut_b(Q[cz]);cut_f(Q[op]);

        if (op <= cz+1) return P;
        for (int i=cz;i<op;++i) P.PB(Q[i]*Q[i+1]);
        if (cz<op+1) P.PB(Q[cz]*Q[op]);
        UNQQ(P).PB(P[0]);
        return P;
    }


    // 分治 - 最近平面点对

    bool cmpy(cPo a, cPo b){return a.y < b.y;}

    inline DB cp(VP &P, int l, int r){
        if (l >= r) return OO;

        int m = (l + r) >> 1; DB d = min(cp(P, l, m), cp(P, m+1, r)), mx = P[m].x;
        inplace_merge(P.begin()+l, P.begin()+m+1, P.begin()+r+1, cmpy);

        VP t; FOR_1(i, l, r) if (sgn(abs(P[i].x - mx), d)<0) t.PB(P[i]);
        REP(i, SZ(t)) FOR(j, i+1,  min(SZ(t), i+9)) checkMin(d, dist2(t[i], t[j])); //#
        return d;
    }

    DB cp(VP& P){
        UNQ(P);
        return cp(P, 0, SZ(P)-1);
    }


    // 最小覆盖圆

    Circle getMinimalCoverCircle(VP& P){ //#
        random_shuffle(ALL(P)); int n = SZ(P);
        Circle C(P[0]); FOR(i, 1, n) if (!~C.sgn(P[i])){
            C = Circle(P[i]); REP(j, i) if (!~C.sgn(P[j])){
                C = Circle(P[i], P[j]); REP(k, j) if (!~C.sgn(P[k])){
                    C = Circle(P[i], P[j], P[k]);
                }
            }
        }
        return C;
    }

    struct Polygon{
        VP P;
        void input();
    };

    inline bool equal(const pair<DB, DB>& lhs, cSeg  rhs){
        DB k, b; rhs.getEquation(k, b);
        return !sgn(k, lhs.fi) && !sgn(b, lhs.se);
    }

    DB getUnion(vector<Polygon>& P, vector<Seg>& S){

        vector<pair<DB,DB> > L; ECH(Si, S){
            DB k, b; Si->getEquation(k, b);
            L.PB(MP(k, b));
        }

        UNQ(L); DB res = 0; ECH(Li, L){

            vector<pair<DB, int> > I;
            Line l0(0,Li->se,1,Li->fi+Li->se);

            ECH(Pi, P){
                int i; for(i=1;i<SZ(Pi->P);++i) if (equal(*Li, Seg(Pi->P[i-1], Pi->P[i]))) break;
                if (i != SZ(Pi->P)) continue;

                VP cut; for(i=1;i<SZ(Pi->P);++i) {
                    Seg l1(Pi->P[i-1], Pi->P[i]); if (!dett(l0,l1)) continue;
                    Po p=l0*l1; if (~l1.sgn(p)) cut.PB(p);
                }

                if (SZ(UNQ(cut)) == 2){
                    I.PB(MP(cut[0].x, 1));
                    I.PB(MP(cut[1].x, -1));
                }
            }

            ECH(Si, S) if (equal(*Li, *Si)){
                I.PB(MP(min(Si->a.x, Si->b.x), 2));
                I.PB(MP(max(Si->a.x, Si->b.x), -2));
            }
    #define h (I[i].fi-I[i-1].fi)
    #define y0 (Li->fi * I[i-1].fi + Li->se)
    #define y1 (Li->fi * I[i].fi + Li->se)
            SRT(I); int c0 = 0, c1 = 0; REP(i, SZ(I)){
                if (!c0 && c1) res += (y0+y1)*h;
                if (abs(I[i].se)==1) c0 += I[i].se;
                else c1 += I[i].se;
            }
    #undef h
    #undef y0
    #undef y1
        }

        return res;
    }

    DB getUnion(vector<Polygon>& P){
        vector<Seg> up, down; ECH(it, P){
            FOR(i, 1, SZ(it->P)){
                Seg s(it->P[i-1], it->P[i]); int t = sgn(s.a.x, s.b.x);
                if (t > 0) up.PB(s); else if (t < 0) down.PB(s);
            }
        }
        return getUnion(P, up) - getUnion(P, down);
    }


    //template<class T> inline DB T::len(){return sqrt(len2());}

    // ... D3

    inline DB dist2(DB x,DB y,DB z){return dist2(x,y)+sqr(z);}

    namespace D3{
        struct Po{
            DB x,y,z;Po(DB x=0,DB y=0,DB z=0):x(x),y(y),z(z){}
            void in(){RF(x,y,z);}

            Po operator-()const{return Po(-x,-y,-z);}
            Po&operator+=(cPo p){x+=p.x,y+=p.y,z+=p.z;rTs;}Po&operator-=(cPo p){x-=p.x,y-=p.y,z-=p.z;rTs;}
            Po&operator*=(DB k){x*=k,y*=k,z*=k;rTs;}Po&operator/=(DB k){x/=k,y/=k,z/=k;rTs;}
            Po operator+(cPo p)const{return Po(x+p.x,y+p.y,z+p.z);}Po operator-(cPo p)const{return Po(x-p.x,y-p.y,z-p.z);}
            Po operator*(DB k)const{return Po(x*k,y*k,z*k);}Po operator/(DB k)const{return Po(x/k,y/k,z/k);}

            DB len2()const{return dist2(x,y,z);}DB len()const{return sqrt(len2());}
            Po&_1(){rTs/=len();}
        };

        inline DB dot(DB x1,DB y1,DB z1,DB x2,DB y2,DB z2){return CG::dot(x1,y1,x2,y2)+z1*z2;}
        inline DB dot(cPo a,cPo b){return dot(a.x,a.y,a.z,b.x,b.y,b.z);}
        inline DB dot(cPo p0,cPo p1,cPo p2){return dot(p1-p0,p2-p0);}
        inline Po det(DB x1,DB y1,DB z1,DB x2,DB y2,DB z2){return Po(CG::det(y1,z1,y2,z2),CG::det(z1,x1,z2,x2),CG::det(x1,y1,x2,y2));}
        inline Po det(cPo a,cPo b){return det(a.x,a.y,a.z,b.x,b.y,b.z);}
        inline Po det(cPo p0,cPo p1,cPo p2){return det(p1-p0,p2-p0);}

        struct Line{
            Po a,b;
        };
    };


} // namespace CG

}  // namespace lastweapon

#endif  // LASTWEAPON_GEOMETRY_HPP
