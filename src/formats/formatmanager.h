#ifndef FORMATMANAGER_H
#define FORMATMANAGER_H

/*
 * Copyright (C) 2007-2009 Sergio Pistone <sergio_pistone@yahoo.com.ar>
 * Copyright (C) 2010-2018 Mladen Milinkovic <max@smoothware.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "format.h"

#include <QString>
#include <QStringList>
#include <QMap>

#include <QUrl>
#include <KEncodingProber>

namespace SubtitleComposer {
class InputFormat;
class OutputFormat;
class Subtitle;
class FormatManager
{
public:
	static FormatManager & instance();

	bool hasInput(const QString &name) const;
	const InputFormat * input(const QString &name) const;
	QStringList inputNames() const;

	bool readSubtitle(Subtitle &subtitle, bool primary, const QUrl &url, QTextCodec **codec, Format::NewLine *newLine = 0, QString *format = 0) const;

	bool hasOutput(const QString &name) const;
	const OutputFormat * output(const QString &name) const;
	const OutputFormat * defaultOutput() const;
	QStringList outputNames() const;

	bool writeSubtitle(const Subtitle &subtitle, bool primary, const QUrl &url, QTextCodec *codec, Format::NewLine newLine, const QString &format, bool overwrite) const;

protected:
	FormatManager();
	~FormatManager();

	QMap<QString, InputFormat *> m_inputFormats;
	QMap<QString, OutputFormat *> m_outputFormats;
};
}
#endif
