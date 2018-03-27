
#include "smallpt.h"

t_vec   radiance(t_smallpt *pt, t_ray r, int depth, int flag)
{
    // t_sphere    *obj;
    double      t;
    int         id;

    (void)flag;
    id = 0;
    if (depth > 10 || !intersect(&pt->scene, &r, &t, &id))
        return ((t_vec){0, 0, 0});

    return (pt->scene.obj[id].c);
}
