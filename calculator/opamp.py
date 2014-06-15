#!/usr/bin/env python

# vref: ADC reference, 5.0 V
# va: positive input of OP1, 1.0 V
# vb: output of OP1
# vc: positive input of OP2
# vt: output of OP2

vref = 5.0

r1 = 4000.0
r2 = 1000.0
r3 = 1000.0
r4 = 10000.0
r5 = 10000.0
r6 = 10000.0
r7 = 100000.0

def calc_vt(rt):
	va = (r2 / (r1 + r2)) * vref
	vb = min(vref, (1 + (rt / r3)) * va)
	vt = min(vref, ((r6 + r7) / (r4 + r5)) * (r5 / r6) * vb - ((r7 / r6) * va))

	return vt

def calc_temp(rt):
	return (rt - 1000.0) * 0.266

for i in range(0, 40):

	rt = 1000.0 + float(i) * 20.0
	vt = calc_vt(rt)
	t = calc_temp(rt)
	adc = (vt * 1024) / vref

	print "rt = %f -> vt = %f (%f C) --> ADC %d (0x%03x)" % (rt, vt, t, adc, adc)

