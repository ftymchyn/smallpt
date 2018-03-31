
#include "smallpt.h"

t_vec   radiance(t_smallpt *pt, t_ray r, t_ushort *xi)
{
    int         depth = 0;
    int         id;
    double      t;
    t_vec       cl = {0, 0, 0};
    t_vec       cf = {1, 1, 1};
    t_surface   surf;

    while (1)
    {
        if (!intersect(&pt->scene, &r, &t, &id))
            return (cl);
        surf = get_surface_properties(pt, r, t, id);
        cl = cl + cf * surf.obj->e;
        if (++depth > 5)
        {
            if(erand48(xi) < surf.maxref)
                surf.f /= (t_vec){surf.maxref, surf.maxref, surf.maxref};
            else
            {
                return (cl);
            }
        }
        cf = cf * surf.f;
        if (surf.obj->refl == DIFF)
            r = diffuse_reflection(surf, xi);
    }
}
