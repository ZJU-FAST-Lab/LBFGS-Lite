#include "lbfgs.hpp"

#include <cstdio>
#include <cstdlib>

class objective_function
{
private:
    double *m_x;

public:
    objective_function() : m_x(NULL)
    {
    }

    ~objective_function()
    {
        if (m_x != NULL)
        {
            free(m_x);
            m_x = NULL;
        }
    }

    int run(int N)
    {
        double fx;
        double *m_x = (double *)malloc(sizeof(double) * N);

        /* Initialize the variables. */
        for (int i = 0; i < N; i += 2)
        {
            m_x[i] = -1.2;
            m_x[i + 1] = 1.0;
        }

        /*
            Start the L-BFGS optimization; this will invoke the callback functions
            evaluate() and progress() when necessary.
         */
        lbfgs::lbfgs_parameter_t lbfgs_params;
        lbfgs::lbfgs_load_default_parameters(&lbfgs_params);
        lbfgs_params.mem_size = 10;
        int ret = lbfgs::lbfgs_optimize(N, m_x, &fx, _evaluate, NULL, _progress, this, &lbfgs_params);

        /* Report the result. */
        printf("L-BFGS optimization terminated with status code = %d\n", ret);
        printf("  fx = %f, x[0] = %f, x[1] = %f\n", fx, m_x[0], m_x[1]);

        return ret;
    }

private:
    static double _evaluate(void *instance,
                            const double *x,
                            double *g,
                            const int n)
    {
        return reinterpret_cast<objective_function *>(instance)->evaluate(x, g, n);
    }

    double evaluate(const double *x,
                    double *g,
                    const int n)
    {
        double fx = 0.0;

        for (int i = 0; i < n; i += 2)
        {
            double t1 = 1.0 - x[i];
            double t2 = 10.0 * (x[i + 1] - x[i] * x[i]);
            g[i + 1] = 20.0 * t2;
            g[i] = -2.0 * (x[i] * g[i + 1] + t1);
            fx += t1 * t1 + t2 * t2;
        }
        return fx;
    }

    static int _progress(void *instance,
                         const double *x,
                         const double *g,
                         const double fx,
                         const double xnorm,
                         const double gnorm,
                         const double step,
                         int n,
                         int k,
                         int ls)
    {
        return reinterpret_cast<objective_function *>(instance)->progress(x, g, fx, xnorm, gnorm, step, n, k, ls);
    }

    int progress(const double *x,
                 const double *g,
                 const double fx,
                 const double xnorm,
                 const double gnorm,
                 const double step,
                 int n,
                 int k,
                 int ls)
    {
        printf("Iteration %d:\n", k);
        printf("  fx = %f, x[0] = %f, x[1] = %f\n", fx, x[0], x[1]);
        printf("  xnorm = %f, gnorm = %f, step = %f\n", xnorm, gnorm, step);
        printf("\n");
        return 0;
    }
};

#define N 100

int main(int argc, char **argv)
{
    objective_function obj;
    return obj.run(N);
}
