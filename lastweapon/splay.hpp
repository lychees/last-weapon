#ifndef LASTWEAPON_SPLAY_HPP
#define LASTWEAPON_SPLAY_HPP 1

#include "lastweapon/io"

namespace lastweapon {

namespace splay {

template <class S, void (*op)(S&, const S, const S), S (*e)()>
struct node {

    static node *NIL; node *c[2], *p;
    int sz; S d;

#define NIL node::NIL
#define l c[0]
#define r c[1]
#define lx x->l
#define rx x->r
#define px x->p
#define ly y->l
#define ry y->r
#define py y->p

    node(S s = e()){d=e();}
    inline void reset(S s){l=r=p=NIL,d=s;sz=1;}

    inline void upd(){
        assert(this != NIL);
        sz = l->sz + 1 + r->sz;
        op(d, l->d, r->d);
    }
    inline int sgn(){return p->r==this;}
    inline void setc(int d,node*x){c[d]=x,px=this;}
    inline void setl(node*x){setc(0,x);}
    inline void setr(node*x){setc(1,x);}

    inline void rot(int d){
        node*y=p,*z=py;z->setc(y->sgn(),this);
        y->setc(d,c[!d]),setc(!d,y),y->upd();
    }
    inline void rot(){rot(sgn());}

    //inline void fix(){if (~sgn()) p->fix(); rls();}

    /*inline node* splay(node*t){
        while (p!=t) rot(); upd();
        return this;
    }*/

    inline node*splay(node*t){
        int a,b;while(p!=t){
            if (p->p==t){rot();break;}
            else a=sgn(),b=p->sgn(),(a^b?this:p)->rot(a),rot(b);
        }
        upd();
        return this;
    }
};


template <class S, void (*op)(S&, const S, const S), S (*e)()>
struct splay {

#define node node<S, op, e>

    std::vector<node> d;
    int n; node* rt;

    splay() : splay(0) {}
    explicit splay(int n) : splay(std::vector<S>(n, e())) {}
    explicit splay(const std::vector<S>& a) : n(int(a.size())) {
        rt = new node(); rt->reset(0);
        REP(i, n) {
            node* t = new node();
            t->reset(a[i]);
            t->setl(rt); t->upd();
            rt = t;
        }
        node* t = new node();
        t->reset(0);
        t->setl(rt); t->upd();
        rt = t;
    }

    node *select(int k, node*t=NIL){
        node *x = rt; while (lx->sz != k){
            if (k < lx->sz) x = lx;
            else k -= lx->sz+1, x = rx;
        }
        if (t == NIL) rt = x;

        return x->splay(t);
    }

    node *select(int a, int b){
        return select(a-1, select(b))->r;
    }

    S prod(int a, int b) {
        return select(a, b)->d;
    }

    void set(int p, S s) {
        node* x = select(p, p+1); x->d = s;
        while (x->p != NIL) {
            x = x->p;
            x->upd();
        }
    }
};

#undef NIL

template <class S, void (*op)(S&, const S, const S), S (*e)()>
node *node::NIL = new node;

#undef node
#undef l
#undef r
#undef lx
#undef rx
#undef px
#undef ly
#undef ry
#undef py

}  // namespace splay

}  // namespace lastweapon

#endif  // LASTWEAPON_SPLAY_HPP
