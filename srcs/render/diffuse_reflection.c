
#include "smallpt.h"

t_ray   diffuse_reflection(t_surface s, t_ushort *xi)
{
    double  r1, r2, r2s;
    double  cos_a, sin_a, k;
    t_vec   w, u, v, d;

    r1 = 2 * M_PI * erand48(xi);
    r2 = erand48(xi);
    r2s = sqrt(r2);
    w = s.nl;
    u = norm(cross((fabs(w[0]) > .1 ? (t_vec){0, 1, 0} : (t_vec){1, 0, 0}), w));
    v = cross(w, u);
    cos_a = cos(r1);
    sin_a = sin(r1);
    k = sqrt(1 - r2);
    u = u * (t_vec){cos_a, cos_a, cos_a} * (t_vec){r2s, r2s, r2s};
    v = v * (t_vec){sin_a, sin_a, sin_a} * (t_vec){r2s, r2s, r2s};
    w = w * (t_vec){k, k, k};
    d = norm(u + v + w);
    return (ray(s.p, d));
}
