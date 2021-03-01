
/* Pointers to functions for writing to a crash report. All JSON types are
 * supported.
 */

#ifndef HDR_IQC_KSCrashReportWriter_h
#define HDR_IQC_KSCrashReportWriter_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <sys/types.h>

/**
 * Encapsulates report writing functionality.
 */
typedef struct IQC_KSCrashReportWriter {
    /**
     * Add a boolean element to the report.
     *
     * @param writer This writer.
     *
     * @param name The name to give this element.
     *
     * @param value The value to add.
     */
    void (*addBooleanElement)(const struct IQC_KSCrashReportWriter *writer,
                              const char *name, bool value);

    /**
     * Add a floating point element to the report.
     *
     * @param writer This writer.
     *
     * @param name The name to give this element.
     *
     * @param value The value to add.
     */
    void (*addFloatingPointElement)(
        const struct IQC_KSCrashReportWriter *writer, const char *name,
        double value);

    /**
     * Add an integer element to the report.
     *
     * @param writer This writer.
     *
     * @param name The name to give this element.
     *
     * @param value The value to add.
     */
    void (*addIntegerElement)(const struct IQC_KSCrashReportWriter *writer,
                              const char *name, long long value);

    /**
     * Add an unsigned integer element to the report.
     *
     * @param writer This writer.
     *
     * @param name The name to give this element.
     *
     * @param value The value to add.
     */
    void (*addUIntegerElement)(const struct IQC_KSCrashReportWriter *writer,
                               const char *name, unsigned long long value);

    /**
     * Add a string element to the report.
     *
     * @param writer This writer.
     *
     * @param name The name to give this element.
     *
     * @param value The value to add.
     */
    void (*addStringElement)(const struct IQC_KSCrashReportWriter *writer,
                             const char *name, const char *value);

    /**
     * Add a string element from a text file to the report.
     *
     * @param writer This writer.
     *
     * @param name The name to give this element.
     *
     * @param filePath The path to the file containing the value to add.
     */
    void (*addTextFileElement)(const struct IQC_KSCrashReportWriter *writer,
                               const char *name, const char *filePath);

    /**
     * Add a JSON element from a text file to the report.
     *
     * @param writer This writer.
     *
     * @param name The name to give this element.
     *
     * @param filePath The path to the file containing the value to add.
     */
    void (*addJSONFileElement)(const struct IQC_KSCrashReportWriter *writer,
                               const char *name, const char *filePath);

    /**
     * Add a hex encoded data element to the report.
     *
     * @param writer This writer.
     *
     * @param name The name to give this element.
     *
     * @param value A pointer to the binary data.
     *
     * @paramn length The length of the data.
     */
    void (*addDataElement)(const struct IQC_KSCrashReportWriter *writer,
                           const char *name, const char *value,
                           const size_t length);

    /**
     * Begin writing a hex encoded data element to the report.
     *
     * @param writer This writer.
     *
     * @param name The name to give this element.
     */
    void (*beginDataElement)(const struct IQC_KSCrashReportWriter *writer,
                             const char *name);

    /**
     * Append hex encoded data to the current data element in the report.
     *
     * @param writer This writer.
     *
     * @param value A pointer to the binary data.
     *
     * @paramn length The length of the data.
     */
    void (*appendDataElement)(const struct IQC_KSCrashReportWriter *writer,
                              const char *value, const size_t length);

    /**
     * Complete writing a hex encoded data element to the report.
     *
     * @param writer This writer.
     */
    void (*endDataElement)(const struct IQC_KSCrashReportWriter *writer);

    /**
     * Add a UUID element to the report.
     *
     * @param writer This writer.
     *
     * @param name The name to give this element.
     *
     * @param value A pointer to the binary UUID data.
     */
    void (*addUUIDElement)(const struct IQC_KSCrashReportWriter *writer,
                           const char *name, const unsigned char *value);

    /**
     * Add a preformatted JSON element to the report.
     *
     * @param writer This writer.
     *
     * @param name The name to give this element.
     *
     * @param value A pointer to the JSON data.
     */
    void (*addJSONElement)(const struct IQC_KSCrashReportWriter *writer,
                           const char *name, const char *jsonElement);

    /**
     * Begin a new object container.
     *
     * @param writer This writer.
     *
     * @param name The name to give this element.
     */
    void (*beginObject)(const struct IQC_KSCrashReportWriter *writer,
                        const char *name);

    /**
     * Begin a new array container.
     *
     * @param writer This writer.
     *
     * @param name The name to give this element.
     */
    void (*beginArray)(const struct IQC_KSCrashReportWriter *writer,
                       const char *name);

    /**
     * Leave the current container, returning to the next higher level
     *  container.
     *
     * @param writer This writer.
     */
    void (*endContainer)(const struct IQC_KSCrashReportWriter *writer);

    /** Internal contextual data for the writer */
    void *context;

} IQC_KSCrashReportWriter;

typedef void (*IQC_KSReportWriteCallback)(
    const IQC_KSCrashReportWriter *writer);

typedef void (*IQCReportCallback)(
        const IQC_KSCrashReportWriter *writer, int type);

#ifdef __cplusplus
}
#endif

#endif // HDR_KSCrashReportWriter_h
