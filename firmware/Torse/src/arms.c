#include "arms.h"

static THD_WORKING_AREA(traking_elbow,256);
static THD_WORKING_AREA(traking_v_shoulder,256);
static THD_WORKING_AREA(traking_h_shoulder,256);

static THD_FUNCTION(elbow_update,arg) {
  (void) arg;
  systime_t time = chVTGetSystemTimeX();
  while (1) {
    elbow_update_angle(0.00002f);
    time = chThdSleepUntilWindowed(time, TIME_MS2I(20)+time);
  }
}

static THD_FUNCTION(v_shoulder_update,arg) {
  (void) arg;
  systime_t time = chVTGetSystemTimeX();
  while (1) {
    v_shoulder_update_angle(0.00002f);
    time = chThdSleepUntilWindowed(time, TIME_MS2I(20)+time);
  }
}

static THD_FUNCTION(h_shoulder_update,arg) {
  (void) arg;
  systime_t time = chVTGetSystemTimeX();
  while (1) {
    h_shoulder_update_angle(0.00002f);
    time = chThdSleepUntilWindowed(time, TIME_MS2I(20)+time);
  }
}

arms_ctx_t arms;

void arms_init(void)
{
  chThdCreateStatic(traking_elbow,sizeof(traking_elbow),NORMALPRIO-2,
                    elbow_update, NULL);

  chThdCreateStatic(traking_v_shoulder,sizeof(traking_v_shoulder),NORMALPRIO-2,
                    v_shoulder_update, NULL);

  chThdCreateStatic(traking_h_shoulder,sizeof(traking_h_shoulder),NORMALPRIO-2,
                    h_shoulder_update, NULL);

  arms.kinematic.arm_length.forearm_length = FOREARM_LENGTH;
  arms.kinematic.arm_length.shoulder_length = SHOULDER_LENGTH;
  arms.kinematic.coord_base.x = BASE_COOR_X;
  arms.kinematic.coord_base.y = BASE_COOR_Y;
  arms.kinematic.coord_base.z = BASE_COOR_Z;
  elbow_init();
  v_shoulder_init();
  h_shoulder_init();
}

void arm_set_coordinates(arm_side_t side, coord_t* target_coordinates)
{
  angles_t target_angles;
  if(arm_inverse_kinematic(&arms.kinematic, target_coordinates, &target_angles, side) == ERROR_NONE)
  {
    h_shoulder_set_angle(target_angles.th1, side);
    elbow_set_angle(target_angles.th2, side);
    v_shoulder_set_angle(target_angles.th3, side);
  }
  else
  {
    return ;
  }

}