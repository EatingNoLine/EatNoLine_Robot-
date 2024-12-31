//
// Created by azarai on 23/09/24.
//

// Scan
  Az_Move_F(0.1, 4000);
HAL_Delay(2000);
Az_Move_B(0.1, 8000);
HAL_Delay(2000);
Az_Move_F(0.1, 4000);

// Grab
Az_Move_B(0.1, 3500);
Az_Move_L(0.1, 6300);
Az_Arm_Grab(&arm[0]);
Az_Com_Shoot();

Az_Move_F(0.1, 200);
Az_Move_L(0.1, 5000);
Az_Move_B(0.1, 200);
Az_Arm_Grab(&arm[0]);
Az_Com_Shoot();

Az_Move_L(0.1, 4500);
Az_Arm_Grab(&arm[0]);
Az_Com_Shoot();

// Rotate
Az_Rotate_1(0.3, 2000);
Az_Rotate_2(0.3, 2000);

Az_Move_L(0.1, 4000);
Az_Arm_Grab(&arm[0]);
Az_Com_Shoot();

Az_Move_F(0.3, 2000);
Az_Rotate_1(0.3, 5000);