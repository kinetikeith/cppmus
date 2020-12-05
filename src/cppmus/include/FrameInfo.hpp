#ifndef FRAMEINFO_HPP
#define FRAMEINFO_HPP

struct FrameInfo
{

	size_t	sampleIndex;
	double	sampleRate;
	
	double	getTime(size_t);

};

inline double FrameInfo::getTime(size_t indexOffset)
{
	
	return double(sampleIndex + indexOffset) / sampleRate;
	
}

#endif /* FRAMEINFO_HPP */
