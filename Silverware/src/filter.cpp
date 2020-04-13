#include <math.h> // fabsf
#include "config.h"

extern float aux[];
extern float aux_analog[];
extern float rxcopy[];
extern float gyro[];

// Most of these filters were made with the filter calculator at  "http://www.schwietering.com/jayduino/filtuino/"
// the sample rate is 1Khz (loop time)



#ifdef SOFT_LPF_1ST_023HZ
//Low pass bessel filter order=1 alpha1=0.023
class  FilterBeLp1
{
	public:
		FilterBeLp1()
		{
			v[0]=0.0;
		}
	private:
		float v[2];
	public:
		float step(float x) //class II
		{
			v[0] = v[1];
			v[1] = (6.749703162983405891e-2f * x)
				 + (0.86500593674033188218f * v[0]);
			return
				 (v[0] + v[1]);
		}
};

FilterBeLp1 filter[3];

#endif

#ifdef SOFT_LPF_1ST_100HZ
//Low pass bessel filter order=1 alpha1=0.1
class  FilterBeLp1
{
	public:
		FilterBeLp1()
		{
			v[0]=0.0f;
		}
	private:
		float v[2];
	public:
		float step(float x) //class II
		{
			v[0] = v[1];
			v[1] = (2.452372752527856026e-1f * x)
				 + (0.50952544949442879485f * v[0]);
			return
				 (v[0] + v[1]);
		}
};

FilterBeLp1 filter[3];
#endif

#ifdef SOFT_LPF_1ST_043HZ
//Low pass bessel filter order=1 alpha1=0.043
// 43Hz 1st order
class  FilterBeLp1
{
	public:
		FilterBeLp1()
		{
			v[0]=0.0f;
		}
	private:
		float v[2];
	public:
		float step(float x) //class II
		{
			v[0] = v[1];
			v[1] = (1.196534197538850347e-1f * x)
				 + (0.76069316049222990284f * v[0]);
			return
				 (v[0] + v[1]);
		}
};

FilterBeLp1 filter[3];
#endif


#ifdef SOFT_LPF_2ND_043HZ
//Low pass bessel filter order=2 alpha1=0.043
// 43Hz 2nd order
class  FilterBeLp2
{
	public:
		FilterBeLp2()
		{
			v[0]=0.0f;
			v[1]=0.0f;
		}
	private:
		float v[3];
	public:
		float step(float x) //class II
		{
			v[0] = v[1];
			v[1] = v[2];
			v[2] = (2.248505631563763041e-2f * x)
				 + (-0.54947452981557831642f * v[0])
				 + (1.45953430455302779478f * v[1]);
			return
				 (v[0] + v[2])
				+2 * v[1];
		}
};

FilterBeLp2 filter[3];
#endif

#ifdef SOFT_LPF_2ND_088HZ
//Low pass bessel filter order=2 alpha1=0.088
// 88hz 2nd order
class  FilterBeLp2
{
	public:
		FilterBeLp2()
		{
			v[0]=0.0f;
			v[1]=0.0f;
		}
	private:
		float v[3];
	public:
		float step(float x) //class II
		{
			v[0] = v[1];
			v[1] = v[2];
			v[2] = (7.420263821683734107e-2f * x)
				 + (-0.28777447277621337474f * v[0])
				 + (0.99096391990886401047f * v[1]);
			return
				 (v[0] + v[2])
				+2 * v[1];
		}
};

FilterBeLp2 filter[3];

#endif

#ifdef SOFT_LPF_4TH_088HZ
//Low pass bessel filter order=4 alpha1=0.088
class  FilterBeLp4
{
	public:
		FilterBeLp4()
		{
			for(int i=0; i <= 4; i++)
				v[i]=0.0f;
		}
	private:
		float v[5];
	public:
		float step(float x) //class II
		{
			v[0] = v[1];
			v[1] = v[2];
			v[2] = v[3];
			v[3] = v[4];
			v[4] = (9.903177770434866065e-3f * x)
				 + (-0.07227144852752773185f * v[0])
				 + (0.49032309909991900199f * v[1])
				 + (-1.33200820239952477664f * v[2])
				 + (1.75550570750017564947f * v[3]);
			return
				 (v[0] + v[4])
				+4 * (v[1] + v[3])
				+6 * v[2];
		}
};

FilterBeLp4 filter[3];
#endif


#ifdef SOFT_LPF_4TH_250HZ
//Low pass bessel filter order=4 alpha1=0.25
class  FilterBeLp4
{
	public:
		FilterBeLp4()
		{
			for(int i=0; i <= 4; i++)
				v[i]=0.0f;
		}
	private:
		float v[5];
	public:
		float step(float x) //class II
		{
			v[0] = v[1];
			v[1] = v[2];
			v[2] = v[3];
			v[3] = v[4];
			v[4] = (1.634284827934446571e-1f * x)
				 + (-0.01499351594000761234f * v[0])
				 + (-0.13250019942726620759f * v[1])
				 + (-0.54107991113589737342f * v[2])
				 + (-0.92628209819194329278f * v[3]);
			return
				 (v[0] + v[4])
				+4 * (v[1] + v[3])
				+6 * v[2];
		}
};
FilterBeLp4 filter[3];
#endif

#ifdef SOFT_LPF_4TH_160HZ
//Low pass bessel filter order=4 alpha1=0.16
class  FilterBeLp4
{
	public:
		FilterBeLp4()
		{
			for(int i=0; i <= 4; i++)
				v[i]=0.0f;
		}
	private:
		float v[5];
	public:
		float step(float x) //class II
		{
			v[0] = v[1];
			v[1] = v[2];
			v[2] = v[3];
			v[3] = v[4];
			v[4] = (5.353739685984656299e-2f * x)
				 + (-0.00850622068385239495f * v[0])
				 + (0.06367126996659371041f * v[1])
				 + (-0.31152539409023977113f * v[2])
				 + (0.39976199504995363343f * v[3]);
			return
				 (v[0] + v[4])
				+4 * (v[1] + v[3])
				+6 * v[2];
		}
};

FilterBeLp4 filter[3];
#endif

#ifdef SOFT_LPF_1ST_HZ

extern "C" float lpfcalc( float sampleperiod , float filtertime);
extern "C" float lpfcalc_hz(float sampleperiod, float filterhz);
extern "C" void lpf( float *out, float in , float coeff);

static float alpha = 0.5;
extern float looptime;

void lpf_coeff()
{
	const float throttle = rxcopy[3];
	float filterHz = SOFT_LPF_1ST_HZ;
	if ( filterHz > SOFT_LPF_1ST_HZ_MAX ) {
		filterHz = SOFT_LPF_1ST_HZ_MAX;
	}
	alpha = FILTERCALC( looptime , 1.0f/filterHz );

 // alpha = FILTERCALC( looptime , (1.0f/SOFT_LPF_1ST_HZ) );
}


class  filter_lpf1
{
    private:
		float lpf_last;
    public:
        filter_lpf1()
    {
      lpf_last = 0;
    }
     float step( float in)
     {
       lpf ( &lpf_last , in , alpha);

       return lpf_last;
     }
};

filter_lpf1 filter[3];
#endif



#ifdef SOFT_LPF_2ND_HZ

extern "C" float lpfcalc( float sampleperiod , float filtertime);
extern "C" float lpfcalc_hz(float sampleperiod, float filterhz);
extern "C" void lpf( float *out, float in , float coeff);

extern float looptime;

static float alpha = 1.0;
static float two_one_minus_alpha = 0.0;
static float one_minus_alpha_sqr = 0.0;
static float alpha_sqr = 1.0;

static float looptime_filt = 0.001;

class  filter_lpf2
{
    private:
		float last_out;
        float last_out2;
    public:
        filter_lpf2()
        {
          last_out = last_out2 = 0;
        }

         float step( float in)
         {

          float ans = in * alpha_sqr + two_one_minus_alpha * last_out
              - one_minus_alpha_sqr * last_out2;

          last_out2 = last_out;
          last_out = ans;

          return ans;
         }
};

void  lpf_coeff_2nd()
{

  lpf ( &looptime_filt , looptime , 0.96);

	const float throttle = rxcopy[ 3 ];
	const float f_base = SOFT_LPF_2ND_HZ_BASE;
	const float f_max = SOFT_LPF_2ND_HZ_MAX;
	const float throttle_breakpoint = SOFT_LPF_2ND_HZ_THROTTLE;
#if 0
	float filterHz = f_base + throttle / throttle_breakpoint * ( f_max - f_base );
#else
	// const float absyaw = fabsf( rxcopy[2] );
	const float absyaw = fabsf( gyro[2] / ( (float)MAX_RATEYAW * DEGTORAD ) );
	float filterHz = f_base + ( throttle / throttle_breakpoint + 0.5f * absyaw ) * ( f_max - f_base );
#endif
	if ( filterHz > f_max ) {
		filterHz = f_max;
	} else if ( filterHz < f_base ) {
		filterHz = f_base;
	}
   float one_minus_alpha = FILTERCALC( looptime_filt , (1.0f/filterHz) );

   one_minus_alpha_sqr = one_minus_alpha * one_minus_alpha;

   two_one_minus_alpha = 2*one_minus_alpha;

   alpha = 1 - one_minus_alpha;
   alpha_sqr = alpha * alpha;

}

filter_lpf2 filter[3];
#endif


#ifdef SOFT_KALMAN_GYRO
class  filter_kalman
{
    private:
        float x_est_last ;
        float P_last ;
        float Q;
        float R;
    public:
        filter_kalman()
        {
            Q = 0.02;
            R = 0.1;

            #ifdef SOFT_KALMAN_GYRO
            R = Q/(float)SOFT_KALMAN_GYRO;
            #endif
        }
        float  step( float in )
        {

            //do a prediction
            float x_temp_est = x_est_last;
            float P_temp = P_last + Q;

            float K = P_temp * (1.0f/(P_temp + R));
            float x_est = x_temp_est + K * (in - x_temp_est);
            float P = (1- K) * P_temp;

            //update our last's
            P_last= P;
            x_est_last = x_est;

            return x_est;
        }
};
filter_kalman filter[3];
#endif


#ifdef SOFT_BIQUAD_NOTCH_HZ
extern "C" float sin_approx( float x );
extern "C" float cos_approx( float x );

static float b0, b1, b2, a0, a1, a2;

extern "C" void notch_init( float filter_f, float Q )
{
    // setup variables
    const float omega = 2.0f * 3.1416f * filter_f * 0.001f;
    const float sn = sin_approx(omega);
    const float cs = cos_approx(omega);
    const float alpha = sn / (2.0f * Q);

    b0 =  1;
    b1 = -2 * cs;
    b2 =  1;
    a0 =  1 + alpha;
    a1 = -2 * cs;
    a2 =  1 - alpha;

    // precompute the coefficients
    b0 /= a0;
    b1 /= a0;
    b2 /= a0;
    a1 /= a0;
    a2 /= a0;
}

extern "C" float notch_filter( float input, int num )
{
	static float notch_hz, notch_q;
	if ( notch_hz != SOFT_BIQUAD_NOTCH_HZ || notch_q != SOFT_BIQUAD_NOTCH_Q ) {
		notch_hz = SOFT_BIQUAD_NOTCH_HZ;
		notch_q = SOFT_BIQUAD_NOTCH_Q;
		notch_init( notch_hz, notch_q );
	}
	static float x1[ 3 ], x2[ 3 ];
#if 1
	static float y1[ 3 ], y2[ 3 ];
	// Direct Form I
	const float result = b0 * input + b1 * x1[ num ] + b2 * x2[ num ] - a1 * y1[ num ] - a2 * y2[ num ];
	x2[ num ] = x1[ num ];
	x1[ num ] = input;
	y2[ num ] = y1[ num ];
	y1[ num ] = result;
	return result;
#else
	// Direct Form II
    const float result = b0 * input + x1[num];
    x1[num] = b1 * input - a1 * result + x2[num];
    x2[num] = b2 * input - a2 * result;
    return result;
#endif
}
#endif


extern "C" float lpffilter( float in,int num )
{
#ifdef SOFT_BIQUAD_NOTCH_HZ
	return notch_filter( in, num );
#else

	#ifdef SOFT_LPF_NONE
	return in;
	#else

    #ifdef SOFT_LPF_1ST_HZ
    if ( num == 0 ) lpf_coeff();
    #endif

    #ifdef SOFT_LPF_2ND_HZ
    if ( num == 0 ) lpf_coeff_2nd();
    #endif

	return filter[num].step(in );
	#endif

#endif
}


// 16Hz hpf filter for throttle compensation
//High pass bessel filter order=1 alpha1=0.016
class  FilterBeHp1
{
	public:
		FilterBeHp1()
		{
			reset();
		}
	private:
		float v[2];
		int holdoff;
	public:
		float step(float x) //class II
		{
			v[0] = v[1];
			v[1] = (9.521017968695103528e-1f * x)
				 + (0.90420359373902081668f * v[0]);
			if ( holdoff > 0 ) {
				--holdoff;
				return 0.0;
			}
			return
				 (v[1] - v[0]);
		}
		void reset()
		{
			v[0] = v[1]	= 0.0;
			holdoff = 200; // ms
		}
};

FilterBeHp1 throttlehpf1;

extern "C" float throttlehpf( float in )
{
	return throttlehpf1.step(in );
}

extern "C" void throttlehpf_reset()
{
	throttlehpf1.reset();
}
