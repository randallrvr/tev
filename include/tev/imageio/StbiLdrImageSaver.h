// This file was developed by Thomas Müller <thomas94@gmx.net>.
// It is published under the BSD 3-Clause License within the LICENSE file.

#pragma once

#include <tev/imageio/ImageSaver.h>

#include <ostream>

TEV_NAMESPACE_BEGIN

class StbiLdrImageSaver : public TypedImageSaver<char> {
public:
    void save(std::ostream& oStream, const filesystem::path& path, const std::vector<char>& data, const Eigen::Vector2i& imageSize, int nChannels) const override;

    bool hasPremultipliedAlpha() const override {
        return false;
    }

    virtual bool canSaveFile(const std::string& extension) const override {
        std::string lowerExtension = toLower(extension);
        return lowerExtension == "jpg"
            || lowerExtension == "jpeg"
            || lowerExtension == "png"
            || lowerExtension == "bmp"
            || lowerExtension == "tga"
            ;
    }
};

TEV_NAMESPACE_END