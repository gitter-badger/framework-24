/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <math.h>
#include <stdint.h>

#define M_SQRT2_F ((float)M_SQRT2)
#define M_PI_F ((float)M_PI)

#define SQ(__X) ((__X)*(__X))

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define SIGN(x) ( x>=0 ? 1 : -1 )

#define LEN(x) (sizeof(x)/sizeof(x[0]))

#define UNUSED(x) ((void)x)

#define LINKED_LIST_APPEND(type, head_ptr, new_item_ptr) { \
    new_item_ptr->next = NULL; \
    type** insert_ptr = &head_ptr; \
    while(*insert_ptr) { \
        insert_ptr = &(*insert_ptr)->next; \
    } \
    *insert_ptr = new_item_ptr; \
}

float sinf_fast(float x);
float cosf_fast(float x);
float constrain_float(float val, float min_val, float max_val);
float wrap_1(float x);
float wrap_2pi(float val);
float wrap_pi(float val);

void transform_a_b_c_to_alpha_beta(float a, float b, float c, float* alpha, float* beta);
void transform_alpha_beta_to_a_b_c(float alpha, float beta, float* a, float* b, float* c);
void transform_d_q_to_alpha_beta(float theta, float d, float q, float* alpha, float* beta);
void transform_alpha_beta_to_d_q(float theta, float alpha, float beta, float* d, float* q);

void hash_fnv_1a(uint32_t len, const uint8_t* buf, uint64_t* hash);
uint16_t crc16_ccitt(const uint8_t* buf, uint32_t len, uint16_t crc);
uint32_t crc32(const uint8_t *buf, uint32_t len, uint32_t crc);
