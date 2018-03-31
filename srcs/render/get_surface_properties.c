
#include "smallpt.h"

t_surface   get_surface_properties(t_smallpt *pt, t_ray r, double t, int id)
{
    t_surface   s;

    s.obj = &pt->scene.obj[id];
    s.p = r.o + r.d * (t_vec){t, t, t};
    s.n = norm(s.p - s.obj->p);
    s.nl = dot(s.n, r.d) < 0 ? s.n : s.n * (t_vec){-1, -1, -1};
    s.f = s.obj->c;
    s.maxref = fmax(fmax(s.f[0], s.f[1]), s.f[2]);
    return (s);
}
