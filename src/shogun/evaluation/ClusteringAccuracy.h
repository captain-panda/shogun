/*
 * This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Authors: Chiyuan Zhang, Roman Votyakov, Yuyu Zhang, Sergey Lisitsyn
 */

#ifndef __CLUSTERINGACCURACY_H__
#define __CLUSTERINGACCURACY_H__

#include <shogun/lib/config.h>

#include <shogun/evaluation/ClusteringEvaluation.h>

namespace shogun
{

/** @brief clustering accuracy
 */
class ClusteringAccuracy: public ClusteringEvaluation
{
public:
	/** constructor */
	ClusteringAccuracy(): ClusteringEvaluation() {}

	/** destructor */
	~ClusteringAccuracy() override {}

	/** @return whether criterium has to be maximized or minimized */
	EEvaluationDirection get_evaluation_direction() const override
	{
		return ED_MINIMIZE;
	}

	/** Returns the name of the SGSerializable instance.  It MUST BE
	 *  the CLASS NAME without the prefixed `C'.
	 *
	 *  @return name of the SGSerializable
	 */
	const char* get_name() const override
	{
		return "ClusteringAccuracy";
	}
protected:
	/** evaluate labels
	 * Make sure to call CClusteringEvaluation::best_map to map the predicted label
	 * before calculating accuracy.
	 *
	 * @param predicted labels for evaluating
	 * @param ground_truth labels assumed to be correct
	 * @return evaluation result
	 */
	float64_t evaluate_impl(std::shared_ptr<Labels> predicted, std::shared_ptr<Labels> ground_truth) override;
};

} // namespace shogun

#endif /* end of include guard: __CLUSTERINGACCURACY_H__ */
