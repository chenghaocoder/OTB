/*
 * Copyright (C) 2005-2017 Centre National d'Etudes Spatiales (CNES)
 *
 * This file is part of Orfeo Toolbox
 *
 *     https://www.orfeo-toolbox.org/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef otbOGRCoordinateTransformationAdapter_h
#define otbOGRCoordinateTransformationAdapter_h

#include "otbOGRSpatialReferenceAdapter.h"

#include "OTBGdalAdaptersExport.h"

#include <memory>
#include <stdexcept>
#include <tuple>


class OGRCoordinateTransformation;

namespace otb
{

/**
 * \class InvalidCoordinateTransfromationException
 * \brief Exception for invalid coordinate transform
 *
 * This class describes an exception that might be thrown by
 * OGRCoordinateTransformationAdapter constructors
 */
class OTBGdalAdapters_EXPORT InvalidCoordinateTransfromationException : public std::runtime_error
{
public:
  InvalidCoordinateTransfromationException(const std::string & description);
  virtual ~InvalidCoordinateTransfromationException() = default;
};

/**
 * \class TransformFailureException
 * \brief Exception for failure of coordinate transform
 *
 * This class describes an exception that might be thrown by
 * OGRCoordinateTransformationAdapter::Transform()
 */
class OTBGdalAdapters_EXPORT TransformFailureException : public std::runtime_error
{
public:
  TransformFailureException(const std::string & description);
  virtual ~TransformFailureException() = default;
};



/**
 * \class OGRCoordinateTransformationAdapter
 * \brief This class is a wrapper around OGRCoordinateTransformation
 * 
 * This class is a wrapper around OGRCoordinateTransformation. It aims
 * at manipulating coordinate transformations between spatial
 * reference systems within OTB, in a safe and easy way. The class
 * constructors enforce RAII: either they fail or they provide a
 * definitive, valid object.
 */

class OTBGdalAdapters_EXPORT OGRCoordinateTransformationAdapter
{
friend bool operator==(const OGRCoordinateTransformationAdapter& ct1, const OGRCoordinateTransformationAdapter& ct2) noexcept;
friend bool operator!=(const OGRCoordinateTransformationAdapter& ct1, const OGRCoordinateTransformationAdapter & ct2) noexcept;

public:
  /** 
   * Builds a coordinate transformation out of source and target
   * spatial reference systems.
   * \param source The source spatial reference
   * \param target The target spatial reference
   *
   * \throws InvalidCoordinateTransfromationException in case of failure
   */
  OGRCoordinateTransformationAdapter(const OGRSpatialReferenceAdapter & source, const OGRSpatialReferenceAdapter & destination);

  /// Destructor
  ~OGRCoordinateTransformationAdapter() noexcept;

  /// Copy constructor
  OGRCoordinateTransformationAdapter(const OGRCoordinateTransformationAdapter& other);

  /// Asignment operator
  OGRCoordinateTransformationAdapter & operator=(const OGRCoordinateTransformationAdapter& other) noexcept;

  /// \return The source spatial reference
  OGRSpatialReferenceAdapter GetSourceSpatialReference() const;

  /// \return The target spatial reference
  OGRSpatialReferenceAdapter GetTargetSpatialReference() const;

  /**
   * Transform a 3D point from source to target spatial reference
   * \param input coords as a 3 double tuple
   * \return output coords as a 3 double tuple
   * \throws TransformFailureException if transform failed
   */
  std::tuple<double,double,double> Transform(const std::tuple<double,double,double> & in) const;

  /**
   * Transform a 2D point from source to target spatial reference
   * \param input coords as a 2 double tuple
   * \return output coords as a 2 double tuple
   * \throws TransformFailureException if transform failed
   */
  std::tuple<double,double> Transform(const std::tuple<double,double> & in) const;

  
private:
  // unique ptr to the internal OGRCoordinateTransformation
  std::unique_ptr<OGRCoordinateTransformation> m_Transform;
};

std::ostream & OTBGdalAdapters_EXPORT operator << (std::ostream& o, const OGRCoordinateTransformationAdapter & i);

  /// equal operator
bool OTBGdalAdapters_EXPORT operator==(const OGRCoordinateTransformationAdapter& ct1, const OGRCoordinateTransformationAdapter& ct2) noexcept;

  /// different operator
bool OTBGdalAdapters_EXPORT operator!=(const OGRCoordinateTransformationAdapter& ct1, const OGRCoordinateTransformationAdapter & ct2) noexcept;

}

#endif
