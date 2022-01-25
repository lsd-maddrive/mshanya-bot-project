#ifndef INCLUDE_LLD_RED_DRIVER_H
#define INCLUDE_LLD_RED_DRIVER_H

#include <common.h>
#include <arm_driver.h>


void lld_red_init_driver(const line_driver_t* pins, const pwm_ctx_t* pwm_ctx);
void lld_red_driver_up(const control_driver_t *control, const pwm_channel_t *pwm_ch, uint16_t period);
void lld_red_driver_down(const control_driver_t *control, const pwm_channel_t *pwm_ch, uint16_t period);
void lld_red_driver_off(const control_driver_t *control, const pwm_channel_t *pwm_ch);



#endif
