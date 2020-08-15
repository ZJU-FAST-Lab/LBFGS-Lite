# LBFGS-Lite
A header-only LBFGS unconstrained optimizer.

## 0. About

__LBFGS-Lite__ is a __C/C++__ [__header-only__](https://en.wikipedia.org/wiki/Header-only) library for __unconstrained optimization__ on __twice continuously differentiable functions__. This code is a modified version of [__liblbfgs__](https://github.com/chokkan/liblbfgs), so that only necessary part is preserved for simplicity.

## 1. Features

- Only one header file "lbfgs.hpp" is required for usage.

- No dependencies except C/C++ standard library.

- The library is an implementation of [__Limited-Memory Broyden-Fletcher-Goldfarb-Shanno__](https://doi.org/10.1007/BF01589116) (LBFGS) with [__More-Thuente Line Search__](https://doi.org/10.1145/192115.192132) to ensure linear time/space complexity and [strong Wolfe conditions](https://en.wikipedia.org/wiki/Wolfe_conditions) in each iteration.

- The objective function is required to be __twice continuously differentiable__ on its domain.

- The library provides an additional callback to obtain maximum feasible stepsize. It can be helpful when the [function is closed on a bounded open domain](https://en.wikipedia.org/wiki/Closed_convex_function) instead of the whole Euclidean space. The callback avoids function evaluations at infeasible region. This can help a lot for closed functions as long as the Newton step is not always clipped.

- Instruction set dependent parts and L1 regularization parts in original code are removed. Multiple files are reorgainzed here with some additional modification.

## 2. How to use

See "lbfgs_sample.cpp" for details.

## 3. Planned features

- LBFGS is only proved to be globally convergent (convergent to stationaries for any initial guess) under convexity assumption, while it also works in many nonconvex cases and yields almost the best results. Slight modification in updating can ensure global convergence without convexity assumption, following a work by [Fukushima and Li](https://doi.org/10.1016/S0377-0427(00)00540-9).

- A better scheme for some special problems than [LBFGS-B](https://doi.org/10.1145/279232.279236) (TOMS778).

- Although More-Thuente line search is already good enough, we plan to compare it with [Hager-Zhang line search](https://doi.org/10.1137/030601880) and [Nocedal's zoom line search](https://link.springer.com/book/10.1007%2F978-0-387-40065-5). Hager-Zhang's method is reported to be full machine accuracy while More-Thuente's method can only attain the half. Nocedal's zoom is also reported to be reliable. We will compare them and choose the best one if the improvement is good enough.

- Further code optimization (instruction set independent) and reorganization.

## 6. Licence

LBFGS-Lite is distributed under the term of the MIT license according the previous version by Okazaki and the initial FORTRAN version by Nocedal. Please refer to LICENSE file in the distribution.

## 7. Maintaince

If any bug, please contact Zhepei WANG (<wangzhepei@live.com>).
