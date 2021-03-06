/*
 * Copyright (C) 2011-2013 Morwenn
 *
 * static_math is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * static_math is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <static_math/array.h>

using namespace smath;


int main()
{
    constexpr array<double> a = { 1.0, 2.1, 3.2, 4.3, 5.4, 6.5 };

    static_assert(a[0] == 1.0, "");
    static_assert(a[3] == 4.3, "");

    static_assert(a.size() == 6, "");

    return 0;
}
