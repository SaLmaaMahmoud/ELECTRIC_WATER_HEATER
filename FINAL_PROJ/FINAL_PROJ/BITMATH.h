/*
 * BITMATH.h
 *
 * Created: 1/20/2021 12:31:45 AM
 *  Author: Salma
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SET_BIT(REG,BIT) (REG |= (1 << BIT))
#define CLEAR_BIT(REG,BIT) (REG &= ~(1 << BIT))
#define TOGGLE_BIT(REG,BIT) (REG ^= (1 << BIT))
#define CLEAR_REG(REG) (REG &= ~(255 << 0))
#define SET_REG(REG) (REG |= ~(255 << 0))
#define IS_SET(REG,BIT) (REG & (1 << BIT))
#define GIT_BIT(REG,BIT) ((REG>>BIT)&1)

#endif /* BITMATH_H_ */